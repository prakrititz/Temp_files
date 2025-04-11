#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    map<string, int> a;
    int n, m;
    string s;
    int ct1, ct2, both;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    {
        cin >> s;
        a[s] = 1;
    }
    for (int i = 0; i < m; ++i)
    {
        cin >> s;
        both += a[s];
        a[s] = 1;
    }

    ct1 = n - both, ct2 = m - both;
    if (both % 2 == 0)
    {
        if (ct1 > ct2)
        {
            cout << "YES\n";
            return 0;
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    else
    {
        if (ct1 > ct2 - 1)
        {
            cout << "YES\n";
            return 0;
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    return 0;
}