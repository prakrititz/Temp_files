#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    if (n % 2)
    {
        if (k % 2)
        {
            n -= k;
            k = k - 1;
        }
        else
        {
            n -= k - 1;
            k = k;
        }
        if (n % k == 0)
        {
            cout << 1 + n / k << endl;
        }
        else
        {
            cout << 2 + n / k << endl;
        }
    }
    else
    {
        if (k % 2)
        {
            n -= k - 1;
            k = k - 1;
        }
        else
        {
            n -= k;
            k = k;
        }
        if (n % k == 0)
        {
            cout << 1 + n / k << endl;
        }
        else
        {
            cout << 2 + n / k << endl;
        }
    }
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