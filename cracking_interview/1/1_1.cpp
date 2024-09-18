#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
bool hasUniqueLetters(string input) {
    map<char, int> char_counter;
    for(char ch: input) {
        if(isalpha(ch)) {
            ch = tolower(ch);
            if(char_counter[ch] > 0){ 
                return false;
            }
            char_counter[ch] ++;
        }
    }
    return true;
}
int main() {
    string input;
    cin >> input;
    cout << hasUniqueLetters(input) << endl;
}