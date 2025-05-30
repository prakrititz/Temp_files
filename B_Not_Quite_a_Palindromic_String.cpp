#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int o = 0, z = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
            o++;
        else
            z++;
    }
    while (k--)
    {
        if (o > z)
            o -= 2;
        else
            z -= 2;
    }
    if (o == z)
        cout << "YES" << endl;
    else
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