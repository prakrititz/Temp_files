#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;

    string s = to_string(n);
    vector<pair<int, int>> ans;
    for (int a = 1; a <= 10000; a++)
    {
        int len = a * s.size();
        string t;
        while (t.size() < 7)
        {
            t += s;
        }
        for (int b = max(1, len - 7); b <= min(len - 1, 10000); b++)
        {
            int res = n * a - b;
            if (to_string(res) == t.substr(0, len - b))
            {
                ans.push_back({a, b});
            }
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
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