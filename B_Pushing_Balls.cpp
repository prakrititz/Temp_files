#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                bool hasZeroLeft = false;
                bool hasZeroAbove = false;
                for (int col = 0; col < j; col++)
                {
                    if (grid[i][col] == '0')
                    {
                        hasZeroLeft = true;
                        break;
                    }
                }

                for (int row = 0; row < i; row++)
                {
                    if (grid[row][j] == '0')
                    {
                        hasZeroAbove = true;
                        break;
                    }
                }

                if (hasZeroLeft && hasZeroAbove)
                {
                    possible = false;
                    break;
                }
            }
        }
        if (!possible)
            break;
    }

    if (possible)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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