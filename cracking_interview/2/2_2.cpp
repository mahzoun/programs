#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data): data(data), next(nullptr) {}
};

class LinkedList {
    public:
        Node* head;
        LinkedList(): head(nullptr) {}
        ~LinkedList() {

        }
        void addNode(int data) {
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
        void display() {
            Node *cur = head;
            while(cur != nullptr){
                std::cout << cur->data << " ";
                cur = cur->next;
            }
            std::cout << std::endl;
        }
        Node* kToLast(int k) {
            Node *start = head, *knext = head;
            int distance = 0;
            while(distance < k && knext != nullptr){
                knext = knext->next;
                distance++;
            }
            if(distance < k){
                return nullptr;
            }
            while(knext != nullptr) {
                knext = knext->next;
                start = start->next;
            }
            return start;
        }
};

int main() {
    LinkedList list;
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(1);
    list.addNode(1);
    list.addNode(1);
    list.addNode(5);
    list.addNode(2);
    list.display();
    cout << list.kToLast(2)->data << endl;
    return 0;
}