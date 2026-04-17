#include<bits/stdc++.h>
using namespace std;

void swapRows(vector<vector<double>>& a, int row, int swapRow) {
    if (row == swapRow) return;
    swap(a[row], a[swapRow]);
}

void applyTransformation(vector<vector<double>>& matrix, int swapRow, int col, int m, int n) {
    double pivotVal = matrix[swapRow][col];
    if (abs(pivotVal) < 1e-9) return; 

    for (int j = 0; j <= m; j++) {
        matrix[swapRow][j] /= pivotVal;
    }
    for (int i = 0; i < n; i++) {
        if (i != swapRow) {
            double factor = matrix[i][col];
            for (int j = 0; j <= m; j++) {
                matrix[i][j] -= factor * matrix[swapRow][j];
            }
        }
    }
}

void gaussJordan(vector<vector<double>>& a, int n, int m) {
    int row = 0;
    for (int col = 0; col < m && row < n; col++) {
        int swapRow = row;
        for (int j = row + 1; j < n; j++) {
            if (abs(a[j][col]) > abs(a[swapRow][col])) {
                swapRow = j;
            }
        }
        if (abs(a[swapRow][col]) < 1e-9) {
            continue; 
        }
        swapRows(a, row, swapRow);
        applyTransformation(a, row, col, m, n);
        row++;
    }
}

int main() {
    int n = 3; 
    int m = 4; 
    vector<vector<double>> matrix = {
        {1, 0, 0, 4},
        {0, 1, 2,  23},
        {0, 0, 0, 9}
    };
    gaussJordan(matrix, n, m);

    cout << "Processed Matrix (Reduced Row Echelon Form):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << fixed << setprecision(2) << setw(6) << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}