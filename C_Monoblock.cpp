#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    long long ans = n * (n + 1) / 2;
    for (long long i = 1; i < n; i++)
    {
        ans += (a[i - 1] != a[i]) * i * (n - i);
    }
    while (m--)
    {
        long long p, x;
        cin >> p >> x;
        p--;
        if (a[p] == x)
        {
            cout << ans << endl;
            continue;
        }
        if (p == 0)
        {
            if (a[0] == a[1] && x != a[1])
                ans += n-1;
            else if (a[0] != a[1] && x == a[1])
                ans -= n-1;
        }
        else if (p == n - 1)
        {
            if (a[n - 1] == a[n - 2] && x != a[n - 2])
                ans += n - 1;
            else if (a[n - 1] != a[n - 2] && x == a[n - 2])
                ans -= n - 1;
        }
        else
        {
            if (a[p] == a[p + 1])
            {
                if (x != a[p + 1])
                {
                    ans += (p + 1) * (n - (p + 1));
                }
            }
            else if (a[p] != a[p + 1])
            {
                if (x == a[p + 1])
                {
                    ans -= (p + 1) * (n - (p + 1));
                }
            }
            if (a[p] == a[p - 1])
            {
                if (x != a[p - 1])
                {
                    ans += p * (n - p);
                }
            }
            else if (a[p] != a[p - 1])
            {
                if (x == a[p - 1])
                {
                    ans -= p * (n - p);
                }
            }
        }
        a[p] = x;
        cout << ans << endl;
    }
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