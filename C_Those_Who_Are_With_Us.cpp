#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int maxi = INT_MIN;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] > maxi)
            {
                maxi = a[i][j];
            }
        }
    }
    int cnt = 0;
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == maxi)
            {
                cnt++;
                r[i]++;
                c[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == maxi)
            {
                if (r[i] + c[j] - 1 == cnt)
                {
                    cout << maxi - 1 << endl;
                    return;
                }
            }
            else
            {
                if (r[i] + c[j] == cnt)
                {
                    cout << maxi - 1 << endl;
                    return;
                }
            }
        }
    }
    cout << maxi << endl;
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