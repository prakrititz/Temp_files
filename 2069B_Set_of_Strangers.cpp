#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    map<int, int> ss;
    map<int, int> dpn;
    vector<int> distinct;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!ss[a[i][j]])
            {
                ss[a[i][j]]++;
                distinct.push_back(a[i][j]);
            }
            if (j + 1 < m && a[i][j + 1] == a[i][j])
                dpn[a[i][j]]++;
            if (i + 1 < n && a[i + 1][j] == a[i][j])
                dpn[a[i][j]]++;
        }
    }
    int s = 1;
    for (int i = 0; i < distinct.size(); i++)
    {
        if (dpn[distinct[i]])
        {
            ans += 2;
            s = 2;
        }
        else
        {
            ans += 1;
        }
    }
    cout << ans - s << endl;
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