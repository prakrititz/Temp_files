#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long ans = 0;
    vector<long long> c(60, 0);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += __builtin_popcountll(a[i]);
        for (long long j = 0; j < 60; j++)
        {
            if (!(1 & (a[i] >> j)))
                c[j]++;
        }
    }
    // k / (1 << i)
    for (long long i = 0; i < c.size(); i++)
    {
        long long val = min(c[i], k >> i);
        k -= val << i;
        ans += val;
    }
    cout << ans << endl;
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