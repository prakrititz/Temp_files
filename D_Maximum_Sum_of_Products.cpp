#include <bits/stdc++.h>
using namespace std;

long long funct(vector<long long> &a, vector<long long> &b, long long i, long long j, vector<vector<long long>> &dp)
{
    if (i < 0 || j >= a.size())
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == j)
    {
        return a[i] * b[j];
    }
    if (i + 1 == j)
    {
        return a[i] * b[j] + a[j] * b[i];
    }
    return dp[i][j] = (a[i] * b[j] + a[j] * b[i]) + funct(a, b, i + 1, j - 1, dp);
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<long long> pre(n);
    pre[0] = a[0] * b[0];
    for (long long i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i] * b[i];
    }
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    long long ans = pre[n - 1];
    for (long long i = 0; i < n; i++)
    {
        for (long long j = i + 1; j < n; j++)
        {
            long long post = pre[n - 1] - pre[j];
            long long front = 0;
            if (i - 1 >= 0)
                front = pre[i - 1];
            long long in = funct(a, b, i, j, dp);
            long long total = post + front + in;
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}