#include <iostream>
using namespace std;

void printGrid(int grid[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool isValid(int grid[5][5], int row, int col, int num) {
    for (int x = 0; x < 5; x++)
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    return true;
}

bool solve(int grid[5][5]) {
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            if (grid[row][col] == 0) {
                for (int num = 1; num <= 5; num++) {
                    if (isValid(grid, row, col, num)) {
                        grid[row][col] = num;
                        if (solve(grid)) return true;
                        grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int grid[5][5] = {
        {1, 0, 0, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 1, 0, 0, 3},
        {0, 0, 0, 2, 0},
        {2, 0, 0, 0, 0}
    };

    cout << "Input Grid:\n";
    printGrid(grid);

    if (solve(grid)) {
        cout << "\nSolved Grid:\n";
        printGrid(grid);
    } else {
        cout << "\nNo solution exists!" << endl;
    }

    return 0;
}
