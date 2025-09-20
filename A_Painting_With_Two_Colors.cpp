#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a > b)
    {
        if (n % 2 == a % 2 && a % 2 == b % 2)
        {
            cout << "YES" << endl;
            return;
        }
    }
    else
    {
        if (n % 2 == b % 2)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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