#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;
bool isPalindromePermutation(string input){
    map<char, int> charCounter;
    for(char ch: input){
        charCounter[tolower(ch)]++;
    }
    int odd_chars = 0;
    for(auto const &x: charCounter){
        cout << x.first << " " << x.second << endl;
        if(x.first != ' ' && x.second % 2 == 1){
            odd_chars++;
        }
    }
    return odd_chars < 2;
}
int main() {
    cout << isPalindromePermutation("Tact coa");
    return 0;
}