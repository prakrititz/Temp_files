#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    if (x == 0)
    {
        if (n == 1)
        {
            cout << -1 << endl;
        }
        else if (n % 2 == 0)
        {
            cout << n << endl;
        }
        else
        {
            cout << n + 3 << endl;
        }
        return;
    }
    if (x == 1)
    {
        if (n % 2 == 0)
        {
            cout << n + 3 << endl;
        }
        else
        {
            cout << n << endl;
        }
        return;
    }
    int ans = x;
    int temp = x;
    int count = 0;
    while (temp)
    {
        temp = temp & (temp - 1);
        count++;
    }
    if (n > count)
    {
        ans += (((n - count) + 1) / 2) * 2;
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