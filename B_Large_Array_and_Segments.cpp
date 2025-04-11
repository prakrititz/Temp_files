#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    long long x;
    cin >> n >> k >> x;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<long long> pref(n + 1, 0);
    long long t = 0;
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
        t += a[i];
    }
    long long ans = 0;
    for (int j = 1; j <= n; j++)
    {
        long long diff = pref[n] - pref[j - 1];
        long long d = 0;
        if (x > diff)
        {
            d = x - diff;
        }
        long long req = 0;
        if (d > 0)
        {
            req = (d + t - 1) / t;
        }
        if (req <= k - 1)
        {
            ans += (k - req);
        }
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}