#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    vector<long long> p(n), s(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        a[i] = lcm(p[i], s[i]);
    }

    long long x = 0;
    for (long long i = 0; i < n; i++)
    {
        x = gcd(x, a[i]);
        if (x != p[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    x = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        x = gcd(x, a[i]);
        if (x != s[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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