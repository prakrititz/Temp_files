#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
void solve()
{
    long long n, k;
    cin >> n >> k;
    for (long long i = 0; i < k; i++)
    {
        long long r, c;
        cin >> r >> c;
        if (r == c)
        {
            n--;
        }
        else
        {
            n -= 2;
        }
    }
    vector<long long> dp(n + 4);
    dp[0] = 1;
    dp[1] = 1;
    for (long long i = 2; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + (2ll * (i - 1) * dp[i - 2]) % MOD) % MOD;
    }
    cout << dp[n] << endl;
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