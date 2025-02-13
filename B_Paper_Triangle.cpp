#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; ++i){
            int x;
            cin >> x;
            mp[x]++;
        }
        
        long long ans = 0;
        int sum = 0;
        for (auto it : mp) {
            long long cnt = it.second;
            if(cnt >= 3)
                ans += cnt * (cnt - 1) * (cnt - 2) / 6;
            if(cnt >= 2)
                ans += cnt * (cnt - 1) / 2 * sum;
            sum += cnt;
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