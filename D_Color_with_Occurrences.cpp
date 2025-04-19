#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<vector<int>> ans;
    int ind = 0;
    while (ind < int(s.size()))
    {
        vector<int> temp = {ind, -1, -1};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= ind && j + a[i].length() <= s.length(); j++)
            {
                if (s.substr(j, a[i].length()) == a[i])
                {
                    temp = max(temp, {j + (int)a[i].length(), i, j});
                }
            }
        }
        if (temp[0] == ind)
        {
            cout << -1 << endl;
            return;
        }
        ind = temp[0];
        ans.push_back(temp);
    }
    cout << ans.size() << endl;
    for (auto it : ans)
    {
        cout << it[1] + 1 << " " << it[2] + 1 << endl;
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