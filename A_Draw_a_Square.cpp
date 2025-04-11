#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    if (l == r && r == d && d == u)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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