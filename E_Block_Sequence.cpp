#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n == 1)
    {
        cout << 1 << endl;
        return;
    }
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int next_pos = i + a[i] + 1;
        if (next_pos <= n)
        {
            dp[i] = dp[next_pos];
        }
        else
        {
            dp[i] = n - i;
        }
        dp[i] = min(dp[i], dp[i + 1] + 1);
    }

    cout << dp[0] << endl;
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