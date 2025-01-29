#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> A(n);
    for(int i = 0; i<n; i++){
        A[i] = 26 - (s[i] - 'A');
    }
    int sum = A[0] + A[1];
    for(int i = 2; i<n; i++){
        if(A[i] != (sum > 26 ? sum%26 : sum)){
            cout << "NO" << endl;
            return 0;
        }
        else{
            sum -= A[i-2];
            sum += A[i];
        }
    }
    cout << "YES" << endl;
    return 0;

    return 0;
}