#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, s;
    cin >> n >> s;
    vector<long long> a(n + 1), minx(n + 1), maxx(n + 1), miny(n + 1), maxy(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] >= s)
        {
            minx[i] = min(s, a[i] - s),
            miny[i] = min(s, a[i] - s),
            maxx[i] = max(s, a[i] - s),
            maxy[i] = max(s, a[i] - s);
        }
        else
        {
            minx[i] = 0;
            miny[i] = 0;
            maxx[i] = a[i];
            maxy[i] = a[i];
        }
    }
    vector<vector<long long>> dp(2, vector<long long>(n + 1));
    for (long long i = 1; i < n; i++)
    {
        if (i == 1)
        {
            dp[0][i] = a[1] * minx[i + 1];
            dp[1][i] = a[1] * maxx[i + 1];
        }
        else if (i == n - 1)
        {
            dp[0][i] = min(a[n] * miny[i] + dp[1][i - 1], a[n] * maxy[i] + dp[0][i - 1]);
        }
        else
        {
            dp[0][i] = min(minx[i + 1] * miny[i] + dp[1][i - 1], minx[i + 1] * maxy[i] + dp[0][i - 1]);
            dp[1][i] = min(maxx[i + 1] * miny[i] + dp[1][i - 1], maxx[i + 1] * maxy[i] + dp[0][i - 1]);
        }
    }
    cout << dp[0][n - 1] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}