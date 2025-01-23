#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int curr_xor = 0;
    int max_xor = 0;
    set<int> prefix_xors;
    prefix_xors.insert(0); 
    for (int i = 0; i < n; i++) {
        curr_xor ^= a[i];
        max_xor = max(max_xor, curr_xor);
        for (int prefix : prefix_xors) {
            max_xor = max(max_xor, curr_xor ^ prefix);
        }
        
        prefix_xors.insert(curr_xor);
    }
    
    cout << max_xor <<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}