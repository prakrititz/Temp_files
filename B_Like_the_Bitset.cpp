#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> p(n);
    int x = n;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            p[i] = x--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            p[i] = x--;
        }
    }

    int len = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            len++;
        }
        else
        {
            len = 0;
        }
        if (len >= k)
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
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