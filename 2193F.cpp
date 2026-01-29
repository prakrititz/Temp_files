#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    int stx, sty, enx, eny;
    cin >> n >> stx >> sty >> enx >> eny;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i]].push_back(b[i]);
    }
    vector<int> xs;
    for (auto &it : mp) {
        sort(it.second.begin(), it.second.end());
        xs.push_back(it.first);
    }
    int k = xs.size();
    vector<vector<int>> dp(k + 1, vector<int>(2, LONG_LONG_MAX));
    dp[0][0] = dp[0][1] = 0;
    int prev_lo = sty, prev_hi = sty;
    for (int i = 1; i <= k; i++) {
        int x = xs[i - 1];
        int lo = mp[x].front();
        int hi = mp[x].back();
        int len = hi - lo;
        dp[i][0] = min(
            dp[i - 1][0] + abs(prev_lo - hi) + len,
            dp[i - 1][1] + abs(prev_hi - hi) + len
        );
        dp[i][1] = min(
            dp[i - 1][0] + abs(prev_lo - lo) + len,
            dp[i - 1][1] + abs(prev_hi - lo) + len
        );
        prev_lo = lo;
        prev_hi = hi;
    }
    int ans = min(
        dp[k][0] + abs(prev_lo - eny),
        dp[k][1] + abs(prev_hi - eny)
    );
    ans += (enx - stx);
    cout << ans <<endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
