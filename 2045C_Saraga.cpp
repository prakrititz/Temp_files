#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    vector<int> pre(26, -1);
    vector<int> suff(26, -1);
    for (int i = 1; i < s.size(); i++)
    {
        if (pre[s[i] - 'a'] == -1)
            pre[s[i] - 'a'] = i;
    }

    for (int i = 0; i < t.size(); i++)
        if (i + 1 < t.size())
            suff[t[i] - 'a'] = i;
    int st = -1, en = -1;
    int minLength = INT_MAX;
    for (int i = 0; i < 26; i++)
    {
        if (pre[i] != -1 && suff[i] != -1)
        {
            int length = (pre[i] + 1 + t.size() - suff[i] - 1);
            if (length < minLength)
            {
                minLength = length;
                st = pre[i],
                en = suff[i];
            }
        }
    }
    if (st != -1 && en != -1)
    {
        for (int i = 0; i < st; i++)
            cout << s[i];
        for (int i = en; i < t.size(); i++)
            cout << t[i];
        cout << endl;
        return;
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}