#include <bits/stdc++.h>
using namespace std;
long long N = 52;
vector<vector<long long>> mp(N, vector<long long>(N, -1));
long long ncr(long long n, long long r)
{
    if (r < 0 || r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;
    if (mp[n][r] != -1)
        return mp[n][r];
    return mp[n][r] = ncr(n - 1, r - 1) + ncr(n - 1, r);
}

long long count(vector<long long> &a, long long b, long long n, long long k)
{
    long long ans = 0;
    long long req = b;
    long long kk = k;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] <= req)
        {
            ans += ncr(n - i - 1, kk);
            req -= a[i];
            kk--;
        }
        if (kk == 0)
        {
            ans++;
            break;
        }
    }
    return ans;
}
void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    long long A, B;
    cin >> A >> B;
    cout << count(a, B, n, k) - count(a, A - 1, n, k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    // cin >> t

    while (t--)
    {
        solve();
    }

    return 0;
}