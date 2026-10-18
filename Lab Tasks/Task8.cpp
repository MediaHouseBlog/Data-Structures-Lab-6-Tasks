#include <iostream>
using namespace std;

bool isSafe(int** arr, int x, int y, int n, bool** visited){
    if(x >= 0 && y >= 0 && x < n && y < n && arr[x][y] == 1 && !visited[x][y]) return true;
    return false;
}

bool ratInMaze(int** arr, int x, int y, int n, int** solArr, bool** visited){
    if(x == (n-1) && y == (n-1) && arr[x][y] == 1){
        solArr[x][y] = 1;
        visited[x][y] = true;
        return true;
    }
    if(isSafe(arr, x, y, n, visited)){
        solArr[x][y] = 1;
        visited[x][y] = true;

        if(ratInMaze(arr, x+1, y, n, solArr, visited)){
            return true;
        }
        if(ratInMaze(arr, x, y+1, n, solArr, visited)){
            return true;
        }
        if(ratInMaze(arr, x-1, y, n, solArr, visited)){
            return true;
        }
        if(ratInMaze(arr, x, y-1, n, solArr, visited)){
            return true;
        }

        cout << "Backtracking from position: (" << x << ", " << y << ")\n";
        solArr[x][y] = 0;
        visited[x][y] = false;
        return false;
    }
    return false;
}

int main() {
    int maze3[3][3] = {
        {1, 1, 1},
        {1, 0, 1},
        {0, 1, 1}
    };

    int n1 = 3;
    int** arr1 = new int*[n1];
    int** solArr1 = new int*[n1];
    bool** visited1 = new bool*[n1];

    for (int i = 0; i < n1; i++) {
        arr1[i] = new int[n1];
        solArr1[i] = new int[n1]();
        visited1[i] = new bool[n1]();
        for (int j = 0; j < n1; j++) {
            arr1[i][j] = maze3[i][j];
        }
    }

    cout << "=== 3x3 Maze Matrix ===\n";
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n1; j++) {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n--- Backtracking Log ---\n";
    if (ratInMaze(arr1, 0, 0, n1, solArr1, visited1)) {
        cout << "\nSolution Matrix:\n";
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n1; j++) {
                cout << solArr1[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path exists.\n";
    }

    for (int i = 0; i < n1; i++) {
        delete[] arr1[i];
        delete[] solArr1[i];
        delete[] visited1[i];
    }
    delete[] arr1;
    delete[] solArr1;
    delete[] visited1;

    cout << "\n===============================\n\n";

    int maze4[4][4] = {
        {1, 1, 1, 0},
        {1, 0, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1}
    };

    int n2 = 4;
    int** arr2 = new int*[n2];
    int** solArr2 = new int*[n2];
    bool** visited2 = new bool*[n2];

    for (int i = 0; i < n2; i++) {
        arr2[i] = new int[n2];
        solArr2[i] = new int[n2]();
        visited2[i] = new bool[n2]();
        for (int j = 0; j < n2; j++) {
            arr2[i][j] = maze4[i][j];
        }
    }

    cout << "=== 4x4 Maze Matrix ===\n";
    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\n--- Backtracking Log ---\n";
    if (ratInMaze(arr2, 0, 0, n2, solArr2, visited2)) {
        cout << "\nSolution Matrix:\n";
        for (int i = 0; i < n2; i++) {
            for (int j = 0; j < n2; j++) {
                cout << solArr2[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No path exists.\n";
    }

    for (int i = 0; i < n2; i++) {
        delete[] arr2[i];
        delete[] solArr2[i];
        delete[] visited2[i];
    }
    delete[] arr2;
    delete[] solArr2;
    delete[] visited2;

    return 0;
}