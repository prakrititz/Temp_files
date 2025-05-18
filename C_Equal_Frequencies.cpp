#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> at(26);
    for (int i = 0; i < n; i++)
    {
        at[s[i] - 'a'].push_back(i);
    }
    vector<pair<int, int>> freq_index;
    for (int i = 0; i < 26; i++)
    {
        freq_index.push_back({(int)at[i].size(), i});
    }
    sort(freq_index.rbegin(), freq_index.rend());
    string res = "";
    int best = -1;
    int ans = 0;
    for (int cnt = 1; cnt <= 26; cnt++)
    {
        if (n % cnt == 0)
        {
            int cur = 0;
            for (int i = 0; i < cnt; i++)
            {
                cur += min(n / cnt, freq_index[i].first);
            }

            if (cur > best)
            {
                best = cur;
                ans = n - best;
                res = string(n, ' ');
                vector<char> extra;

                for (int it = 0; it < cnt; it++)
                {
                    int idx = freq_index[it].second;
                    for (int j = 0; j < n / cnt; j++)
                    {
                        if (j < (int)at[idx].size())
                        {
                            res[at[idx][j]] = (char)('a' + idx);
                        }
                        else
                        {
                            extra.push_back((char)('a' + idx));
                        }
                    }
                }

                for (char &c : res)
                {
                    if (c == ' ')
                    {
                        c = extra.back();
                        extra.pop_back();
                    }
                }
            }
        }
    }

    cout << ans << endl;
    cout << res << endl;
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