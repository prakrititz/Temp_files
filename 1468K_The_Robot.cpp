#include <bits/stdc++.h>
using namespace std;
// sili mistake 
void solve()
{
    string s;
    cin >> s;

    vector<pair<long long, long long>> obs;
    long long cx = 0, cy = 0;
    for (long long j = 0; j < s.size(); j++)
    {
        if (s[j] == 'R')
        {
            cx++;
        }
        else if (s[j] == 'L')
        {
            cx--;
        }
        else if (s[j] == 'U')
        {
            cy++;
        }
        else if (s[j] == 'D')
        {
            cy--;
        }
        obs.push_back({cx, cy});
    }
    pair<long long, long long> ans = {0, 0};
    for (long long i = 0; i < obs.size(); i++)
    {
        long long cx = 0, cy = 0;
        long long ox = obs[i].first, oy = obs[i].second;

        for (long long j = 0; j < s.size(); j++)
        {
            if (s[j] == 'R')
            {
                if (!(cx + 1 == ox && cy == oy))
                    cx++;
            }
            else if (s[j] == 'L')
            {
                if (!(cx - 1 == ox && cy == oy))
                    cx--;
            }
            else if (s[j] == 'U')
            {
                if (!(cx == ox && cy + 1 == oy))
                    cy++;
            }
            else if (s[j] == 'D')
            {
                if (!(cx == ox && cy - 1 == oy))
                    cy--;
            }
        }

        if (cx == 0 && cy == 0)
        {
            ans = {ox, oy};
            break; // Stop checking after finding the first valid obstacle
        }
    }

    cout << ans.first << " " << ans.second << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
