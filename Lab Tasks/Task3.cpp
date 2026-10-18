#include <iostream>
using namespace std;

// Slower Recursive
int powerSlow(int x, int n) {
    if (n == 0) return 1;
    return x * powerSlow(x, n - 1);
}

// Faster Recursive
int powerFast(int x, int n) {
    if (n == 0) return 1;

    int half = powerFast(x, n / 2);

    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}

int main() {
    cout << "Slow 2^5: " << powerSlow(2, 5) << endl;
    cout << "Fast 2^5: " << powerFast(2, 5) << endl;
    return 0;
}