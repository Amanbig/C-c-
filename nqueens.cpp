#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void solveNQueens(int n);
void placeQueens(int n, int row, vector<int>& colPlacements, int& totalSolutions);
bool canPlace(int row, int col, const vector<int>& colPlacements);
void printBoard(const vector<int>& colPlacements);

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    auto start = high_resolution_clock::now();

    solveNQueens(n);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}

void solveNQueens(int n) {
    vector<int> colPlacements(n);
    int totalSolutions = 0;
    placeQueens(n, 0, colPlacements, totalSolutions);
    cout << "Total solutions: " << totalSolutions << endl;
}

void placeQueens(int n, int row, vector<int>& colPlacements, int& totalSolutions) {
    if (row == n) {
        totalSolutions++;
        cout << "Solution " << totalSolutions << ": ";
        printBoard(colPlacements);
        return;
    }

    for (int col = 0; col < n; col++) {
        if (canPlace(row, col, colPlacements)) {
            colPlacements[row] = col;
            placeQueens(n, row + 1, colPlacements, totalSolutions);
        }
    }
}

bool canPlace(int row, int col, const vector<int>& colPlacements) {
    for (int i = 0; i < row; i++) {
        if (colPlacements[i] == col || colPlacements[i] - col == i - row ||
            colPlacements[i] - col == row - i) {
            return false;
        }
    }
    return true;
}

void printBoard(const vector<int>& colPlacements) {
    int n = colPlacements.size();
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (colPlacements[row] == col) {
                cout << "Q ";
            } else {
                cout << "- ";
            }
        }
        cout << endl;
    }
    cout << endl;
}
