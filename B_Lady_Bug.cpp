#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ao = 0;
    int bo = 0;
    int ae = 0;
    int be = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i] == '0')
        {

            ao++;
        }
        if (b[i] == '0')
        {
            bo++;
        }
    }
    for (int i = 1; i < n; i += 2)
    {
        if (a[i] == '0')
        {
            ae++;
        }
        if (b[i] == '0')
        {
            be++;
        }
    }
    if (ao + be >= (n + 1) / 2 && (ae + bo) >= (n) / 2)
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