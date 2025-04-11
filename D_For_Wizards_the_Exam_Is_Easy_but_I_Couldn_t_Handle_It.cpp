#include <bits/stdc++.h>
using namespace std;

void solve() {
     int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        
        int change = 0; 
        int L = 0, R = 0;
        for (int l = 0; l < n; l++){
            int delta = 0;
            for (int r = l + 1; r < n; r++){
                if(a[r] > a[l])
                    delta++; 
                else if(a[r] < a[l])
                    delta--;
                if(delta < change){
                    change = delta;
                    L = l;
                    R = r;
                }
            }
        }
        
        if(change < 0)
            cout << L + 1 << " " << R + 1 << "\n";
        else
            cout << 1 << " " << 1 << "\n";
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