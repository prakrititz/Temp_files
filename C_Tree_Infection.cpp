#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n - 1; i++)
        cin >> d[i];
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        deg[d[i]]++;
    }
    vector<pair<int, int>> sizes;
    sizes.push_back({1, 1});
    for (int i = 0; i < deg.size(); i++)
    {
        if (deg[i] > 0)
            sizes.push_back({deg[i], i});
    }
    sort(sizes.rbegin(), sizes.rend());
    // for (int i = 0; i < sizes.size(); i++)
    // {
    //     cout << sizes[i].second << " " << sizes[i].first << endl;
    // }
    // cout << endl;
    // cout << endl;
    int l = sizes.size(), r = n;
    int s = sizes.size();
    while (l < r)
    {
        int x = (l + r) / 2;

        int cnt = 0;
        for (int i = 0; i < s; i++)
        {
            cnt += max(0, sizes[i].first - x + i);
        }
        if (s + cnt <= x)
        {
            r = x;
        }
        else
        {
            l = x + 1;
        }
    }
    cout << l << endl;
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