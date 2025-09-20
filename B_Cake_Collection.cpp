#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    long long i = 0;
    while (m && i < n)
    {
        ans += (m)*a[i];
        m--;
        i++;
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