#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x;
    cin >> n >> x;
    vector<long long> a(n);
    for (auto &i : a)
        cin >> i;
    vector<long long> pre(n + 1, 0);
    for (long long i = 0; i < n; i++)
        pre[i + 1] = pre[i] + a[i];
    vector<long long> dp(n + 1, 0);
    if (a[n - 1] <= x)
        dp[n - 1] = 1;
    for (long long i = n - 2; i >= 0; i--)
    {
        auto j = upper_bound(pre.begin(), pre.end(), pre[i] + x) - pre.begin();
        // cout << a[i] << " " << j << endl;
        if (j == n + 1)
        {
            dp[i] = dp[i + 1] + 1;
        }
        else
        {
            long long ind = upper_bound(pre.begin(), pre.end(), pre[i] + x) - pre.begin();
            dp[i] = dp[ind] + ind - 1 - i;
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << endl;
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