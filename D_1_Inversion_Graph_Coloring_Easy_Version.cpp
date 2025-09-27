#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long f(long long i, vector<long long> &a, vector<vector<vector<long long>>> &dp, long long ol, long long tl, long long n)
{
    if (i == n)
        return 1;
    if (dp[i][ol][tl] != -1)
        return dp[i][ol][tl];
    long long ans = f(i + 1, a, dp, ol, tl, n);
    long long nol = ol, ntl = tl;
    if (a[i] > ol)
        nol = a[i];
    if (a[i] < ol && a[i] > tl)
        ntl = a[i];
    ans %= mod;
    if (a[i] < tl)
        return dp[i][ol][tl] = ans;
    ans += f(i + 1, a, dp, nol, ntl, n) % mod;
    ans %= mod;
    return dp[i][ol][tl] = ans;
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(n + 1, -1)));
    cout << f(0, a, dp, 0, 0, n) << endl;
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