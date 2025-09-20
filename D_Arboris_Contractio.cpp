#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> deg(n, 0);
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    if (n == 2)
    {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    vector<int> lf(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
        {
            lf[i] = 1;
            ans++;
        }
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int lfc = 0;
        for (int j = 0; j < g[i].size(); j++)
        {
            if (lf[g[i][j]])
                lfc++;
        }
        total = max(total, lfc);
    }
    cout << ans - total << endl;
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