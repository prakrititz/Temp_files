#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long cnt(long long x)
{
    long long count = 0;
    while (x)
    {
        if (x % 2)
            count++;
        x /= 2;
    }
    return count;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(64, 0));
    for (long long i = 1; i <= n; i++)
    {
        long long val = a[i - 1];
        for (long long j = 0; j <= 63; j++)
        {
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            dp[i][j & val] = (dp[i][j & val] + dp[i - 1][j]) % MOD;
        }
        dp[i][val] = (dp[i][val] + 1) % MOD;
    }
    long long ans = 0;
    for (long long i = 0; i <= 63; i++)
    {
        if (cnt(i) == k)
            ans = (ans + dp[n][i]) % MOD;
    }
    cout << ans << endl;
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