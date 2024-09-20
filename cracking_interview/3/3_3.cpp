#include <iostream>
using namespace std;
const int MAXSIZE = 100;
template <typename T>
class Stack{
    int top_index; 
    public: 
        T st[MAXSIZE];
        Stack() { top_index = -1; }
        bool push(T value);
        T pop();
        T top();
        bool isEmpty();
};

template <typename T> 
bool Stack<T>::push(T value) {
    // check if stack is full 
    if(top_index == MAXSIZE - 1) {
        return false;
    }
    top_index++;
    st[top_index] = value;
    return true;
}

template <typename T> 
T Stack<T>::pop() {
    if(top_index == -1) {
        return NULL;
    }
    top_index--;
    return st[top_index + 1];
}

template <typename T> 
T Stack<T>::top() {
    cout << top_index << endl;
    if(top_index == 0) {
        return NULL;
    }
    return st[top_index + 1];
}

template <typename T> 
bool Stack<T>::isEmpty() {
    return top_index == -1;
}

int main() {
    Stack<int> st;
    cout << st.isEmpty() << endl;
    st.push(1);
    st.push(2);
    st.push(3);
    int _tmp = st.pop();
    cout << st.top() <<endl;
    return 0;
}