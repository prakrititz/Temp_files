#include<bits/stdc++.h>
using namespace std;

// For explanation refer to comments in 1b

#define int long long

vector<vector<int>> MM(vector<vector<int>> &A, vector<vector<int>> &B, int m){
    int n1 = A.size(), m1 = A[0].size();
    int n2 = B.size(), m2 = B[0].size();
    vector<vector<int>> C(n1, vector<int>(m2));
    for(int i = 0; i<n1; i++){
        for(int j = 0; j<m2; j++){
            int sum = 0;
            for(int k = 0; k<n2; k++){
                sum = (sum + (A[i][k] + B[k][j])%m)%m;
            }
            C[i][j] = sum;
        }
    }
    return C;
}

vector<vector<int>> power(vector<vector<int>> x, string &n, int m){
    int row = (int)x.size();
    int col = (int)x[0].size();
    vector<vector<int>> res(row, vector<int>(col, 1));
    int size = n.size();
    // Instead of actually dividing, just iterate from right to left
    for(int i = size-1; i>=0; i--){
        if(n[i] == '1'){
            res = MM(res, x, m);
        }
        x = MM(x, x, m);
    }
    return res;
}

int32_t main(){
    // Taking inputs
    int k;
    cin >> k;
    vector<vector<int>> x(k, vector<int>(k));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            cin >> x[i][j];
        }
    }
    
    string n;
    cin >> n;
    
    int m;
    cin >> m;


    vector<vector<int>> res = power(x, n, m);
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}