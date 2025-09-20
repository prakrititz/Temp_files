#include <bits/stdc++.h>
using namespace std;

int K = 32;
vector<int> dp(K);
const int mod = 1e9 + 7;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(K, 0);
    int minBig = mod;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x < K)
            a[x] = 1;
        else
            minBig = min(minBig, x);
    }

    long long ans = 1;
    while (m > 0)
    {
        int p = 1;
        while (p < K && a[p] == 0)
            p++;

        if (p == K)
        {
            ans = ans * minBig % mod;
            m--;
            for (int i = 1; i < K; i++)
                a[i] = 1;
        }
        else if ((1 << (p - 1)) <= m)
        {
            m -= (1 << (p - 1));
            a[p] = 0;
            ans = ans * dp[p] % mod;
        }
        else
        {
            m--;
            a[p] = 0;
            ans = ans * p % mod;
            for (int i = 1; i < p; i++)
                a[i] = 1;
        }
    }
    cout << ans % mod << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1] = 1;
    for (int k = 2; k < K; k++)
    {
        long long val = k;
        for (int i = 1; i < k; i++)
        {
            val = val * dp[i] % mod;
        }
        dp[k] = val % mod;
    }

    int t;
    cin >> t;
    while (t--)
        solve();
}
