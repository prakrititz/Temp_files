#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if (n % p == 0 && m != q * (n / p))
    {
        cout << "NO" << endl;
        ;
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