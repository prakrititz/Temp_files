#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;
    vector<int> w(7);
    
    int t = 0;
    for (int i = 0; i < 7; i++) {
        cin >> w[i];
        t += w[i]; 
    }

    int ans = INT_MAX;

    for (int i = 0; i < 7; i++) {
        if (w[i] == 0) continue;  // Can only i on a class day

        int f = max(0, (k / t) - 1);  
        int d = f * 7;
        int cnr = f * t;

        int j = i;
        while (cnr < k) {
            if (w[j % 7] == 1) {
                cnr++;
            }
            d++;
            j++;
        }

        ans = min(ans, d);
    }

    cout << ans << endl;
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
