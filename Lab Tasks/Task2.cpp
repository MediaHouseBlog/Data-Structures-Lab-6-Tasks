//Write a recursive function that reverses a string. Hint: reverse(s) = reverse(everything after the first
//character) + first character. Base case: length = 1.
#include <iostream>
#include <string>
using namespace std;

string reverse(string s) {
    if (s.length() <= 1) {
        return s;
    }

    return reverse(s.substr(1)) + s[0];
}

int main() {
    string word = "HELLO";
    cout << "Original: " << word << endl;
    cout << "Reversed: " << reverse(word) << endl;
    return 0;
}


//string reverse(string s, int start, int end){
//	if(start>end) return "";
//	char st = s[start];
//	string sol = reverse(s,start+1,end);
//	sol+= st;
//	return sol;
//}---