#include<bits/stdc++.h>
using namespace std;

#define int long long

string divideStringByTwo(string& number){
    string result;
    int remainder = 0;

    for(char c : number){
        // 1. Convert char digit to integer
        int digit = c - '0';
        
        // 2. Combine with remainder from previous step
        int value = remainder * 10 + digit;
        
        // 3. Calculate quotient digit and new remainder
        int quotient = value / 2;
        remainder = value % 2;
        
        // 4. Append quotient to result
        result.push_back(quotient + '0');
    }

    // 5. Remove leading zeros
    // We iterate until we reach the last character to ensure "0" is returned for input "0" or "1"
    reverse(result.begin(), result.end());
    while((int)result.size() > 1 && result.back() == '0'){
        result.pop_back();
    }
    reverse(result.begin(), result.end());
    return result;
}

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
    while(n != "0"){
        int idx = (int)n.size()-1;
        int lastDig = n[idx] - '0';
        if(lastDig%2){
            res = MM(res, x, m);
        }
        x = MM(x, x, m);
        n = divideStringByTwo(n);
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