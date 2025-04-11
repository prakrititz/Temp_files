#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, n, m;
    cin >> x >> n >> m;
    int x2 = x;
    int n2 = n;
    int m2 = m;
    while (x > 0 && n--)
    {
        x = x / 2;
    }
    while (x > 1 && m--)
    {
        x = (x + 1) / 2;
    }
    while (x2 > 1 && m2--)
    {
        x2 = (x2 + 1) / 2;
    }
    while (x2 > 0 && n2--)
    {
        x2 = x2 / 2;
    }
    cout << x2 << " " << x << endl;
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