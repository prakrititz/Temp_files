#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n + 1);
    for (long long i = 1; i <= n; ++i)
        cin >> a[i];

    long long S = 0;
    for (long long i = 1; i <= n; ++i)
    {
        if (i % 2 == 1)
            S += a[i];
        else
            S -= a[i];
    }
    long long fo = 1, fe = 2;
    long long le, lo;
    if (n % 2)
    {
        lo = n;
        le = n - 1;
    }
    else
    {
        lo = n - 1;
        le = n;
    }
    if (n == 1)
    {
        cout << a[1] << endl;
        return;
    }
    else if (n == 2)
    {
        cout << max(a[1] - a[2], 1 + a[2] - a[1]) << endl;
        return;
    }

    long long same = 0;
    if ((fo - lo) != 0)
        same = max(same, (long long)(lo - fo));
    if ((fe - le) != 0)
        same = max(same, (long long)(le - fe));
    long long cross = LLONG_MIN;
    long long odd = LLONG_MAX;
    for (long long i = 1; i <= n; ++i)
    {
        if (i % 2 == 1)
        {
            odd = min(odd, 2LL * a[i] + i);
        }
        else
        {
            if (odd != LLONG_MAX)
            {
                cross = max(cross, (2LL * a[i] + i) - odd);
            }
        }
    }

    long long even = LLONG_MIN;
    for (long long i = 1; i <= n; ++i)
    {
        if (i % 2 == 0)
        {
            even = max(even, 2LL * a[i] - i);
        }
        else
        {
            if (even != LLONG_MIN)
            {
                cross = max(cross, even - (2LL * a[i] - i));
            }
        }
    }
    long long ans = 0;
 ans = max(0LL, same);
    if (cross != LLONG_MIN)
        ans = max(ans, cross);
    if (ans == LLONG_MIN)
        ans = 0;
    cout << (S + ans) << endl;
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