#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n; 
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    int maxi = 1;
    int cur = 1; 

    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1]) {
            cur++; 
        } else {
            cur = 1;
        }
        maxi = max(maxi, cur);
    }

    cout << maxi << endl; 

    return 0;
}
