#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    if (k == 1)
    {
        long long x = max(a[0], a[n - 1]);
        if (x == a[0])
        {
            a[0] = -1;
        }
        else
        {
            a[n - 1] = -1;
        }
        long long t = 0;
        for (long long i = 0; i < n; i++)
            t = max(t, a[i]);
        cout << t + x << endl;
        return;
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    if (k == n)
        k--;
    for (long long i = 0; i < k + 1; i++)
    {
        ans += a[i];
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