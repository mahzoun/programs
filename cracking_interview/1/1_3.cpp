#include <iostream>
#include <string>
#include <cassert>

using namespace std;
string URLify(string input, u_int32_t strLen) {
    int idx = 0;
    assert(strLen <= input.length());
    for(int i = 0; i < strLen; i++) {
        if(input[i] == ' ') {
            input.replace(i, 1, "20%");
            i += 2;
            strLen += 2;
        }
    }
    return input;
}

int main() {
    cout << URLify("1 2 3     ", 6) << endl;
    cout << URLify("", 0) << endl;
    cout << URLify("     ", 2) << endl;
    cout << URLify("3456789089", 8) << endl;
    return 0;
}