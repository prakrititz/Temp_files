#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 2;
int mod  = 1e9+7;
int power(int base, int exp) {
    int res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int powv2(int base, int exp) {
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
                matrix[i][j] = (matrix[i][j] - val + MOD) % MOD;
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
int findRank(vector<vector<int>>&M)
{
    int c = 0;
    for(int i = M.size()-1;i>=0;i--)
    {
        for(int j= 0;j<M[i].size();j++)
        {
            if(M[i][j]){
                return c;
            }
        }
        c++;
    }
    return c;
}
vector<int>Primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<int>>M(n, vector<int>(20));
    for(int i= 0;i<n;i++){
        cin>>a[i];
        for(int j = 0;j<19;j++)
        {
            int c = 0;
            while(a[i]%Primes[j]==0)
            {
                a[i]/=Primes[j];
                c++;
            }
            M[i][j] = c%2;
        }
        M[i][19] = 0;
    }
    gaussJordan(M, n, 20);
    int R = findRank(M);
    cout<<powv2(2, R)-1<<endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
}