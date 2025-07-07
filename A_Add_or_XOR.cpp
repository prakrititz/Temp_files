#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long a, b, x, y;
    cin >> a >> b >> x >> y;
    if (b + 1 < a)
    {
        cout << -1 << endl;
    }

    else if (b + 1 == a)
    {
        if ((a ^ 1) == b)
        {
            cout << y << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if (b == a + 1)
    {
        if (a % 2 == 0)
        {
            cout << min(x, y) << endl;
        }
        else
        {
            cout << x << endl;
        }
    }
    else
    {
        if (x <= y)
        {
            cout << (b - a) * x << endl;
        }
        else
        {
            long long d = b - a;
            long long t = d - d / 2;
            if (a % 2 == 0)
            {
                long long ans = d / 2 * x;
                ans += t * y;
                cout << ans << endl;
            }
            else
            {
                long long ans = d / 2 * y;
                ans += t * x;
                cout << ans << endl;
            }
        }
    }
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