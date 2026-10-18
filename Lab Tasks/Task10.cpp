#include <iostream>
#include <cmath>

using namespace std;

bool isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

int countAllSolutions(int board[], int n, int row = 0) {
    if (row == n) return 1;

    int total = 0;
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            total += countAllSolutions(board, n, row + 1);
            board[row] = -1;
        }
    }
    return total;
}

int main() {
    int n = 8;
    int* board = new int[n];
    for (int i = 0; i < n; i++) board[i] = -1;

    int total = countAllSolutions(board, n);
    cout << "Total solutions for N = " << n << ": " << total << "\n";

    delete[] board;
    return 0;
}