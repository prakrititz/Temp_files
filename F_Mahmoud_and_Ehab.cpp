#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 2; 
int mod = 1e9+7;

int power(int base, int exp) {
    int res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int modInverse(int n) {
    return power(n, MOD - 2);
}

void swapRows(vector<vector<int>>& a, int row, int swapRow) {
    if (row == swapRow) return;
    swap(a[row], a[swapRow]);
}

void applyTransformation(vector<vector<int>>& matrix, int pivotRow, int col, int m, int n) {
    int pivotVal = matrix[pivotRow][col];
    int inv = modInverse(pivotVal); 

    for (int j = 0; j < m; j++) {
        matrix[pivotRow][j] = (matrix[pivotRow][j] * inv) % MOD;
    }

    for (int i = 0; i < n; i++) {
        if (i != pivotRow) {
            int factor = matrix[i][col];
            if (factor == 0) continue;

            for (int j = 0; j < m; j++) {
                int val = (factor * matrix[pivotRow][j]) % MOD;
                matrix[i][j] = (matrix[i][j] - val) % MOD;
                if (matrix[i][j] < 0) matrix[i][j] += MOD;
            }
        }
    }
}

void gaussJordan(vector<vector<int>>& a, int n, int m) {
    int row = 0;
    for (int col = 0; col < m && row < n; col++) {
        int swapRow = row;
        for (int j = row; j < n; j++) {
            if (a[j][col] != 0) {
                swapRow = j;
                break;
            }
        }
        if (a[swapRow][col] == 0) {
            continue; 
        }
        swapRows(a, row, swapRow);
        applyTransformation(a, row, col, m, n);
        row++;
    }
}

int findRank(vector<vector<int>>&M, int n, int m) {
    int rank = 0;
    for(int i = 0; i < n; i++) {
        bool allZero = true;
        for(int j = 0; j < m; j++) {
            if(M[i][j]) {
                allZero = false;
                break;
            }
        }
        if(!allZero) rank++;
    }
    return rank;
}

void solve(){
    int n, x;
    cin >> n >> x;
    vector<vector<int>> M(n + 1, vector<int>(20));
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        for(int j = 0; j < 20; j++) {
            if ((val >> j) & 1) M[i][j] = 1;
            else M[i][j] = 0;
        }
    }
    for(int j = 0; j < 20; j++) {
        if ((x >> j) & 1) M[n][j] = 1;
        else M[n][j] = 0;
    }
    vector<vector<int>> M_without_X = M;
    M_without_X.pop_back(); 
    gaussJordan(M_without_X, n, 20);
    int rankOriginal = findRank(M_without_X, n, 20);
    gaussJordan(M, n + 1, 20);
    int rankWithX = findRank(M, n + 1, 20);
    if (rankWithX > rankOriginal) {
        cout << 0 << endl;
    } else {
        cout << power(2, n - rankOriginal) << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}