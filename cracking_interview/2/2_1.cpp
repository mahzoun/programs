#include <iostream>
#include <map>
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
        void deleteNode(int data) {
            Node *prev = head, *target = head;
            while(target->data != data and target != nullptr) {
                prev = target;
                target = target->next;
            }
            if(target != nullptr) {
                prev->next = target->next;
                delete target;
            }
        }
        void removeDuplicates() {
            map<int, int> dataCounter;
            Node *cur = head;
            Node *prev = nullptr;
            while(cur != nullptr) {
                int cur_data = cur->data;
                dataCounter[cur_data]++;
                if(dataCounter[cur_data] > 1) {
                    prev->next = cur->next; 
                    delete cur;
                    cur = prev->next;

                } else {
                    prev = cur;
                    cur = cur->next;
                }
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
        ~LinkedList() {
            Node *cur = head;
            Node *next;
            while(cur != nullptr){
                next = cur->next;
                delete cur;
                cur = next;
            }
            head = nullptr;
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
    list.deleteNode(3);
    list.addNode(5);
    list.addNode(2);
    list.display();
    list.removeDuplicates();
    list.display();
    return 0;
}