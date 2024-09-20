#include <iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *next;
        Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
    public: 
        Node *head;
        LinkedList(): head(nullptr) {}
        ~LinkedList() {}
        void addNode(int data) {
            cout << "a called" << endl;
            Node *nextNode = new Node(data);
            Node *last = head;
            if(head == nullptr) {
                head = nextNode;
            } else {
                while(last->next != nullptr) {
                    last = last->next;
                }
                last->next = nextNode;
            }
        }
        LinkedList reverse() {
            cout << "r called" << endl;
            LinkedList reversed;
            Node *current = this->head;
            while(current != nullptr) {
                Node *nextNode = new Node(current->data);
                nextNode->next = reversed.head;
                reversed.head = nextNode;
                current = current->next;
            }
            return reversed;

        }
        bool Equal(LinkedList list) {
            cout << "e called" << endl;
            Node *iterator1 = this->head;
            Node *iterator2 = (&list)->head;
            while(iterator1 != nullptr and iterator2 != nullptr) {
                if(iterator1->data != iterator2->data) {
                    return false;
                }
                iterator1 = iterator1->next;
                iterator2 = iterator2->next;
            }
            if(iterator1 != nullptr or iterator2 != nullptr) {
                return false;
            }
            return true;
        }
        bool IsPalindrome() {
            return Equal(reverse());
        }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(3);
    list.addNode(2);
    list.addNode(2);
    cout << list.IsPalindrome() << endl;
    return 0;
}