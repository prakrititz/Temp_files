#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> ans(n, vector<int>(m));
    int rep = (n * m) / k;
    int curr_rep = 0;
    if (m % k)
    {
        int curr = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (curr == k + 1)
                {
                    curr = 1;
                }
                cout << curr << " ";
                curr++;
            }
            cout << endl;
        }
    }
    else
    {
        int curr = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans[i][(j + i) % m] = curr;
                curr++;
                if (curr == k + 1)
                {
                    curr = 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
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