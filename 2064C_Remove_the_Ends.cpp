#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> pos(n);
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pos[0] = max(0LL, a[0]);
    for (long long i = 1; i < n; i++)
    {
        pos[i] = pos[i - 1] + max(0LL, a[i]);
    }
    vector<long long> neg(n);
    neg[n - 1] = abs(min(a[n - 1], 0LL));
    for (long long i = n - 2; i >= 0; i--)
    {
        neg[i] = neg[i + 1] + abs(min(a[i], 0LL));
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        ans = max(neg[i] + pos[i], ans);
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