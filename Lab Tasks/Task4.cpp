#include <iostream>
#include <string>
using namespace std;

bool palindromeCheck(string s, int start, int end) {
    if (start >= end) return true;
    
    char st = s[start];
    char en = s[end];
    if (st == en) {
        if (palindromeCheck(s, start + 1, end - 1))
            return true;
    }
    return false;
}

bool palindromeCheck(string s) {
    return palindromeCheck(s, 0, s.length() - 1);
}

int main() {
    cout << boolalpha;

    cout << "AGGA:  " << palindromeCheck("AGGA") << endl;
    cout << "RADAR: " << palindromeCheck("RADAR") << endl;
    cout << "HELLO: " << palindromeCheck("HELLO") << endl;

    return 0;
}