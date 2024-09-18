#include <iostream>
#include <string>
#include <map>
using namespace std;
bool isPermutation(string s1, string s2) {
    if(s1.length() != s2.length()) 
        return false;
    map<char, int> charCounter;
    for (char ch: s1) {
        charCounter[ch]++;
    }
    for (char ch: s2) {
        charCounter[ch]--;
        if (charCounter[ch] < 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cout << isPermutation("hiiiiih", "iiiiihh") << endl;
    cout << isPermutation("jhk", "") << endl;
    cout << isPermutation("", "") << endl;
    return 0;
}
