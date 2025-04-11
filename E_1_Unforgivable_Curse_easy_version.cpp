#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    map<char, int> s1;
    map<char, int> s2;
    map<char, int> t1;
    map<char, int> t2;
    if (n <= 3)
    {
        if (s == t)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (n == 4)
    {
        map<char, int> ss, tt;
        ss[s[0]]++, ss[s[3]]++;
        tt[t[0]]++;
        tt[t[3]]++;
        bool v = true;
        for (auto it : ss)
        {
            if (it.second != tt[it.first])
            {
                v = false;
            }
        }
        if (s[1] == t[1] && s[2] == t[2] && v)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else if (n == 5)
    {
        map<char, int> ss, tt;
        for (int i = 0; i < n; i++)
        {
            if (i != 2)
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
        if (s[2] == t[2] && v)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
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