#include<bits/stdc++.h>
using namespace std;

// For safety, we take everything to be long long
#define int long long

// For explanation refer to comments in 1a

// Instead of normal multiplication, we do matrix multiplication
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

vector<vector<int>> power(vector<vector<int>> x, int n, int m){
    int row = (int)x.size();
    int col = (int)x[0].size();
    vector<vector<int>> res(row, vector<int>(col, 1));
    while(n){
        if(n%2){
            res = MM(res, x, m);
        } 
        x = MM(x, x, m);
        n = n/2;
    }
    return res;
}

int32_t main(){
    // Taking Inputs
    int k;
    cin >> k;
    vector<vector<int>> x(k, vector<int>(k));
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            cin >> x[i][j];
        }
    }
    int n, m;
    cin >> n >> m;

    vector<vector<int>> res = power(x, n, m);
    for(int i = 0; i<k; i++){
        for(int j = 0; j<k; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}