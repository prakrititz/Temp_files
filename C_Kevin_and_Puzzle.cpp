#include <bits/stdc++.h>
using namespace std;
long long MOD = 998244353;
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n == 1)
    {
        if (a[0] == 0)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
        return;
    }
    map<vector<long long>, long long> dp;
    if (a[0] != 0)
    {
        dp[{1, 1}] = 1;
    }
    else
    {
        dp[{1, 1}] = 1;
        dp[{0, 0}] = 1;
    }
    for (long long i = 1; i < n; i++)
    {
        map<vector<long long>, long long> mp2;
        mp2[{a[i], 0}] = (dp[{a[i], 0}] + dp[{a[i], 1}]) % MOD;
        mp2[{a[i - 1] + 1, 1}] = dp[{a[i - 1], 0}];
        dp = mp2;
    }
    cout << (dp[{a[n - 2] + 1, 1}] + dp[{a[n - 1], 0}]) % MOD << endl;
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