#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long ans = LLONG_MAX;
    long long p1 = 0;
    while (p1 < n)
    {
        long long p2 = p1;
        while (p2 < n && a[p2] == a[p1])
            p2++;
        long long val = a[p1];
        long long k = p2 - p1;
        ans = min(ans, (n - k) * val);
        p1 = p2;
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