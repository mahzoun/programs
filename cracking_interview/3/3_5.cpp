#include <iostream>
#include <stack>
using namespace std;

void sort(stack<int>& st) {
  stack<int> sorted;
  while (!st.empty()) {
    int cur = st.top();
    st.pop();
    if (sorted.empty()) {
      sorted.push(cur);
    } else {
      while (cur > sorted.top()) {
        int tmp = sorted.top();
        sorted.pop();
        st.push(tmp);
        if(sorted.empty()) {
            break;
        }
      }
      sorted.push(cur);
      while (st.top() < sorted.top()) {
        int tmp = st.top();
        st.pop();
        sorted.push(tmp);
        if (st.empty() | sorted.empty()) {
            break;
        }
      }
    }
  }
  st = sorted;
}

int main() {
  stack<int> st;
  int arr[6] = {3, 1, 2, 4, 5, 0};
  for (int i : arr) {
    st.push(i);
  }
  sort(st);
  while (!st.empty()) {
    cout << st.top() << endl;
    st.pop();
  }
  return 0;
}