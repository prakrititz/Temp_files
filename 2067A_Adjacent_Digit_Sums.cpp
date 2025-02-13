#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    if (y - x == 1)
    {
        cout << "YES" << endl;
    }
    else if (x > y && (x - y + 1) % 9 == 0)
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