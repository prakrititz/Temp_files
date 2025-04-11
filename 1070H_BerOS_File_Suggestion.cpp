#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];
    map<string, set<int>> fs;
    for (int i = 0; i < n; i++)
    {
        int len = s[i].size();
        for (int j = 1; j <= len; j++)
        {
            for (int k = 0; k < len; k++)
            {
                if (k + j - 1 < s[i].size())
                {
                    fs[s[i].substr(k, j)].insert(i);
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        string ss;
        cin >> ss;
        if (fs[ss].size() == 0)
        {
            cout << 0 << " -" << endl;
        }
        else
        {
            cout << fs[ss].size() << " " << s[*fs[ss].begin()] << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int t;
    // cin >> t;
    int t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}