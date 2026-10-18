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

bool solveFirst(int board[], int n, int row = 0) {
    if (row == n) return true;

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            if (solveFirst(board, n, row + 1)) return true;
            board[row] = -1;
        }
    }
    return false;
}

void printBoard(int board[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i] == j ? " Q " : " . ");
        }
        cout << "\n";
    }
    cout << "\n";
}

int main() {
    int sizes[] = {4, 5, 6, 8};
    for (int n : sizes) {
        int* board = new int[n];
        for (int i = 0; i < n; i++) board[i] = -1;
        
        cout << "=== Board Solution for N = " << n << " ===\n";
        if (solveFirst(board, n)) {
            printBoard(board, n);
        }
        delete[] board;
    }

    for (int n = 2; n <= 3; n++) {
        int* board = new int[n];
        for (int i = 0; i < n; i++) board[i] = -1;
        
        cout << "=== Testing N = " << n << " ===\n";
        if (!solveFirst(board, n)) {
            cout << "No valid placement exists for N = " << n << "\n\n";
        }
        delete[] board;
    }

    return 0;
}

/*


 N = 2 (2x2 Grid):
   Placing a queen in any cell attacks its entire row, column, and main diagonal.
   This eliminates 3 out of the 4 total cells on the board, leaving no valid space 
   in the second row for another queen.

 N = 3 (3x3 Grid):
   Placing 2 non-attacking queens on a 3x3 board forces their attack lines (horizontal, 
   vertical, and diagonal) to overlap every remaining cell in the 3rd row. The maximum 
   number of non-attacking queens that can physically fit on a 3x3 board is 2, making 
   N = 3 impossible.
*/