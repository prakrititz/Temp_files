#include <bits/stdc++.h>
using namespace std;

void solve()
{
    map<int, int> color;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            dp[i] = 0;
            color[a[i]] = i;
        }
        else
        {
            dp[i] = dp[i + 1];
            if (color.count(a[i]))
            {
                dp[i] = max(dp[i], 1 - i + color[a[i]]);
                color[a[i]] = max(color[a[i]], dp[i + 1] + i);
            }
            else
            {
                color[a[i]] = dp[i + 1] + i;
            }
        }
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