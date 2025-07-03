#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    vector<long long> a(n);
    a[0] = 1e18;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        ans += a[i];
        a[i] = n - i - a[i];
    }
    if (k >= n)
    {
        cout << 0 << endl;
        return;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < k; i++)
    {
        ans += a[i];
        ans -= i + 1;
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