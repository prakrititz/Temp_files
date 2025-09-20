#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> h(n);
    for (long long i = 0; i < n; i++)
        cin >> h[i];

    long long free = 1 - n;
    for (long long i = 0; i < n; i++)
        free += h[i];
    vector<long long>
        dp(n, 0);
    for (long long i = 1; i < n; i++)
    {
        long long w = min(i, h[i]);
        w -= 2;
        if (w < 0)
            w = 0;

        if (i == 1)
        {
            dp[i] = w;
        }
        else
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + w);
        }
    }

    cout << (free - dp[n - 1]) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
