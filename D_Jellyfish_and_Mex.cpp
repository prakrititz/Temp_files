#include <bits/stdc++.h>
using namespace std;
int findmex(vector<int> &arr)
{
    int n = arr.size();
    vector<bool> present(n + 1, false);
    for (int x : arr)
    {
        if (x <= n)
        {
            present[x] = true;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if (!present[i])
        {
            return i;
        }
    }
    return n + 1;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (mp[0] == 0)
    {
        cout << 0 << endl;
        return;
    }
    n = findmex(a);
    vector<vector<long long>> dp(n, vector<long long>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = (mp[0] - 1) * i;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = dp[i - 1][j];
            long long curr = (mp[i] - 1) * j + i + dp[i - 1][i];
            dp[i][j] = min(dp[i][j], curr);
        }
    }

    cout << dp[n - 1][n] << endl;
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