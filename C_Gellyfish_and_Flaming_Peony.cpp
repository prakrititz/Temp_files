#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        g = gcd(g, a[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == g)
            cnt++;
        a[i] /= g;
    }
    if (cnt > 0)
    {
        cout << n - cnt << endl;
        return;
    }
    vector<int> dp(6000, 6000);
    dp[1] = n;
    for (int i = 1; i <= 5000; i++)
    {
        for (auto x : a)
        {
            int g = gcd(i, x);
            dp[i] = min(dp[i], dp[g] + 1);
        }
    }
    int ans = INT_MAX;
    for (auto x : a)
    {
        ans = min(ans, dp[x]);
    }
    cout << ans - 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}