#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * Swaps two rows in the augmented matrix.
 */
void swapRows(vector<vector<double>>& matrix, int row1, int row2) {
    if (row1 == row2) return;
    swap(matrix[row1], matrix[row2]);
}

/**
 * Applies the transformation: 
 * 1. Normalizes the pivot row so the pivot element is 1.
 * 2. Eliminates the current column in all other rows.
 */
void applyTransformation(vector<vector<double>>& matrix, int pivotRow, int col, int n) {
    double pivotVal = matrix[pivotRow][col];

    for (int j = 0; j <= n; j++) {
        matrix[pivotRow][j] /= pivotVal;
    }
    for (int i = 0; i < n; i++) {
        if (i != pivotRow) {
            double factor = matrix[i][col];
            for (int j = 0; j <= n; j++) {
                matrix[i][j] -= factor * matrix[pivotRow][j];
            }
        }
    }
}

/**
 * Performs Gauss-Jordan Elimination.
 * Assumes the system is non-degenerate (unique solution exists).
 */
void gaussJordan(vector<vector<double>>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        int pivotRow = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(matrix[k][i]) > abs(matrix[pivotRow][i])) {
                pivotRow = k;
            }
        }
        swapRows(matrix, i, pivotRow);
        applyTransformation(matrix, i, i, n);
    }
}

int main() {
    // Example: 3x3 system
    // 2x + y - z = 8
    // -3x - y + 2z = -11
    // -2x + y + 2z = -3
    int n = 3;
    vector<vector<double>> matrix = {
        {2, 1, -1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    gaussJordan(matrix, n);

    cout << "Solutions:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x" << i + 1 << " = " << fixed << setprecision(2) << matrix[i][n] << endl;
    }

    return 0;
}