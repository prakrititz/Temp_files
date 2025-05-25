#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp)
{
    long long res = 1;
    base %= MOD;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    map<long long, long long> mp;
    vector<long long> b;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] == 1)
            b.push_back(a[i]);
    }
    if (b.size() < m)
    {
        cout << 0 << endl;
        return;
    }
    sort(b.begin(), b.end());
    vector<long long> c;
    for (long long i = 0; i < b.size(); i++)
    {
        c.push_back(mp[b[i]]);
    }
    long long tot = 0;
    long long prev = c[0];
    long long cur = 1;
    for (long long i = 0; i < m; i++)
    {
        cur = (cur * c[i]) % MOD;
    }
    if (b[m - 1] - b[0] < m)
        tot = cur;
    for (long long i = 1; i <= b.size() - m; i++)
    {

        cur = (cur * mod_pow(prev, MOD - 2)) % MOD;
        cur = (cur * c[i + m - 1]) % MOD;
        prev = c[i];
        if (b[i + m - 1] - b[i] < m)
        {
            tot = (tot + cur) % MOD;
        }
    }

    cout << tot << endl;
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