#include <iostream>
using namespace std;

template <typename T>
class Node {
    public:
        T data;
        Node *next;
        Node(T val): data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
    public:
        Node<T> *head;
        LinkedList() : head(nullptr) {}
        void AddNode(T data){
            Node<T> *newNode = new newNode<T>(val);
            this->head->next = nullptr;
            newNode->next = this->head; 
        }
        
}