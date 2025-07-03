#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (a[j - 1] > a[j])
            {
                swap(a[j - 1], a[j]);
                ans.push_back({1, j});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (b[j - 1] > b[j])
            {
                swap(b[j - 1], b[j]);
                ans.push_back({2, j});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            ans.push_back({3, i + 1});
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
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