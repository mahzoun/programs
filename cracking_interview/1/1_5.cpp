#include <iostream>
#include <string>
#include <map>
using namespace std;
bool isOneWay(string s1, string s2) {
    if(s2.length() > s1.length()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    bool flag = false;
    if(s1.length() - s2.length() > 1) {
        return false;
    }
    for(int i = 0, j = 0; i < s1.length(), j < s2.length();) {
        // cout << i << " " << j << " " << flag << endl;
        if(s1[i] != s2[j]) {
            if(flag) {
                return false;
            }
            flag = true;
            if(s1.length() == s2.length()) {
                i++;
                j++;
            } else { 
                i++;
            }
        } else {
            i++;
            j++;
        }
    }
    return true;
}

int main() {
    // cout << isOneWay("abcd", "abc");
    // cout << isOneWay("", "");
    cout << isOneWay("abcd", "abec");
}