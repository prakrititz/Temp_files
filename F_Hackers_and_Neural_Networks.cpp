#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    vector<vector<string>> b(m, vector<string>(n));
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int maxi = 0;
    int ind = -1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> b[i][j];
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[i][j])
            {
                cnt++;
            }
        }
        if (maxi < cnt)
        {
            maxi = cnt;
            ind = i;
        }
    }
    if (ind == -1)
    {
        cout << -1 << endl;
        return;
    }
    bool check = 0;
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[ind][i])
            c[i] = 1;
    }

    int x = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[j] == b[i][j] && c[j] == 0)
            {
                x++;
                c[j] = 1;
            }
        }
    }
    if (x >= n - maxi)
    {
        cout << n + 2 * (n - maxi) << endl;
    }
    else
    {
        cout << -1 << endl;
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