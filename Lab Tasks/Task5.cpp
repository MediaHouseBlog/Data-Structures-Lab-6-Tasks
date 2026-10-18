#include <iostream>
using namespace std;

int factorial(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorial(n - 1, n * acc);
}

int main() {
    cout << "0! = " << factorial(0) << endl;
    cout << "1! = " << factorial(1) << endl;
    cout << "5! = " << factorial(5) << endl;
    cout << "6! = " << factorial(6) << endl;

    return 0;
}