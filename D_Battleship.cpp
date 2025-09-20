#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<vector<int>> a(11, vector<int>(11, 0));
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        int D, L, R, C;
        cin >> D >> L >> R >> C;

        if (D == 0)
        {
            if (C + L - 1 > 10)
                f = false;
            for (int j = 0; j < L && f; j++)
            {
                int r = R, c = C + j;
                if (r < 1 || r > 10 || c < 1 || c > 10 || a[r][c])
                {
                    f = false;
                    break;
                }
                a[r][c] = 1;
            }
        }
        else
        {
            if (R + L - 1 > 10)
                f = false;
            for (int j = 0; j < L && f; j++)
            {
                int r = R + j, c = C;
                if (r < 1 || r > 10 || c < 1 || c > 10 || a[r][c])
                {
                    f = false;
                    break;
                }
                a[r][c] = 1;
            }
        }
    }

    if (f)
        cout << "Y" << endl;
    else
        cout << "N" << endl;
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