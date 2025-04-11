#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
void solve()
{
    int n, m, d;
    cin >> n >> m >> d;

    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(m, vector<long long>(2, 0)));
    vector<vector<vector<long long>>> pre(n, vector<vector<long long>>(m + 1, vector<long long>(2, 0)));

    for (int i = 0; i < m; i++)
    {
        if (s[n - 1][i] == 'X')
        {
            dp[n - 1][i][0] = 1;
        }
    }

    for (int i = 0; i < m; i++)
    {
        pre[n - 1][i + 1][0] = (pre[n - 1][i][0] + dp[n - 1][i][0]) % MOD;
    }

    for (int i = 0; i < m; i++)
    {
        if (s[n - 1][i] == '#')
            continue;
        int low = max(0, i - d), high = min(m - 1, i + d);
        dp[n - 1][i][1] = ((pre[n - 1][high + 1][0] - pre[n - 1][low][0])%MOD - dp[n - 1][i][0])%MOD;
    }

    for (int i = 0; i < m; i++)
    {
        pre[n - 1][i + 1][1] = (pre[n - 1][i][1] + dp[n - 1][i][1]) % MOD;
    }

    int sq = sqrt(d * d - 1);

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
                continue;
            int low = max(0, j - sq), high = min(m - 1, j + sq);
            dp[i][j][0] = pre[i + 1][high + 1][0] - pre[i + 1][low][0];
            dp[i][j][0] = ((dp[i][j][0] + pre[i + 1][high + 1][1]) % MOD - pre[i + 1][low][1]) % MOD;
        }
        for (int j = 0; j < m; j++)
        {
            pre[i][j + 1][0] = (pre[i][j][0] + dp[i][j][0]) % MOD;
        }
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '#')
                continue;
            int low = max(0, j - d), high = min(m - 1, j + d);
            dp[i][j][1] = ((pre[i][high + 1][0] - pre[i][low][0])%MOD - dp[i][j][0])%MOD;
        }
        for (int j = 0; j < m; j++)
        {
            pre[i][j + 1][1] = (pre[i][j][1] + dp[i][j][1]) % MOD;
        }
    }

    cout << (pre[0][m][0] + pre[0][m][1] )%MOD<< endl;
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
