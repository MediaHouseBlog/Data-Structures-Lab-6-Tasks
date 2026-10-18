#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    return fib(n - 1) + fib(n - 2);
}

int fibmemo(int n, int* memo) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    if (memo[n] == 0) {
        memo[n] = fibmemo(n - 1, memo) + fibmemo(n - 2, memo);
    }

    return memo[n];
}

int main() {
    int n = 40;

    auto start1 = high_resolution_clock::now();
    int result1 = fib(n);
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(end1 - start1);

    cout << "Naive fib(" << n << ") = " << result1 
         << " | Time taken: " << duration1.count() << " ms" << endl;

    int memo[50] = {0};

    auto start2 = high_resolution_clock::now();
    int result2 = fibmemo(n, memo);
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);

    cout << "Memoized fib(" << n << ") = " << result2 
         << " | Time taken: " << duration2.count() << " microseconds" << endl;

    return 0;
}