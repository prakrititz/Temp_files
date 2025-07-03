#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n + 1);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
    for (int i = 1; i <= k; i++)
        dp[0][i] = 1e18;
    for (long long i = 1; i <= n; i++)
    {

        long long curr = a[i - 1];
        for (long long opp = 0; opp <= k; opp++)
        {
            // no operation att all
            dp[i][opp] = dp[i - 1][opp] + curr;
        }
        long long mini = 1e18;
        for (long long len = 0; len <= min(i - 1, k); len++)
        {
            mini = min(mini, a[i - len - 1]);
            for (long long opp = len; opp <= k; opp++)
            {
                dp[i][opp] = min(dp[i][opp], dp[i - len - 1][opp - len] + 1ll * mini * (len + 1));
            }
        }
    }
    cout << dp[n][min(n - 1, k)] << endl;
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