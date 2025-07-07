#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, l, r, k;
    cin >> n >> l >> r >> k;
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    else if (n == 1)
    {
        cout << l << endl;
        return;
    }
    if (n % 2)
    {
        cout << l << endl;
        return;
    }
    else
    {
        long long x = 1;
        while (x <= l)
        {
            x <<= 1;
        }
        if (x <= r)
        {
            if (k <= n - 2)
            {
                cout << l << endl;
                return;
            }
            else
            {
                cout << x << endl;
                return;
            }
        }
        else
        {
            cout << -1 << endl;
            return;
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