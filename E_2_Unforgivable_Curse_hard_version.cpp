#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    map<char, int> s2;
    map<char, int> t2;
    if (n <= k)
    {
        if (s == t)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return;
    }
    int len = max(0, n - (n - k) * 2);
    if (len == 0)
    {
        for (int i = 0; i < n; i++)
        {
            s2[s[i]]++;
            t2[t[i]]++;
        }
        bool y = true;
        for (auto it : s2)
        {
            if (it.second != t2[it.first])
            {
                y = false;
            }
        }
        if (y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        return;
    }
    else
    {
        string subs = s.substr(n - k, len), subt = t.substr(n - k, len);
        map<char, int> ss, tt;
        for (int i = 0; i < n; i++)
        {
            if (i < n - k || i > n - k + len-1)
            {
                ss[s[i]]++;
                tt[t[i]]++;
            }
        }
        bool v = true;
        for (auto it : ss)
        {
            if (it.second != tt[it.first])
            {
                v = false;
            }
        }
        if (subs == subt && v)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
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