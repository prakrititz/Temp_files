#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool f = true;
    int mini = min(a, b);
    int maxi = max(a, b);
    int x = maxi / 2;
    int y = ((maxi) % 2 != 0);
    if (mini < (x + y - 1))
    {
        f = false;
    }
    c -= a;
    d -= b;
    mini = min(c, d);
    maxi = max(c, d);
    x = maxi / 2;
    y = ((maxi) % 2 != 0);
    if (mini < (x + y - 1))
    {
        f = false;
    }
    if (!f)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
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