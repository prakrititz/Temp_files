#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<pair<int, int>> l;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        l.push_back({x, i + 1});
    }
    sort(l.rbegin(), l.rend());
    map<int, int> mp;
    vector<int> ans(m);
    int k;
    for (int i = n - 1; i >= l[0].first - 1; i--)
    {
        mp[a[i]]++;
    }
    for (auto it : mp)
    {
        ans[l[0].second - 1]++;
    }
    for (int i = 1; i < l.size(); i++)
    {
        ans[l[i].second - 1] = ans[l[i - 1].second - 1];
        for (int j = l[i].first - 1; j < l[i - 1].first - 1; j++)
        {
            if (mp[a[j]] == 0)
            {
                ans[l[i].second - 1]++;
            }
            mp[a[j]]++;
        }
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
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