#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<vector<int>> nxt(k, vector<int>(n + 2, n + 1));

    for (int c = 0; c < k; c++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] - 'a' == c)
                nxt[c][i] = i + 1;
            else
                nxt[c][i] = nxt[c][i + 1];
        }
    }

    vector<int> f(n + 2);
    for (int i = n; i >= 0; i--)
    {
        f[i] = INT_MAX;
        for (int x = 0; x < k; x++)
        {
            f[i] = min(f[i], 1 + f[nxt[x][i]]);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;

        int x = 0;
        for (auto c : t)
        {
            x = nxt[c - 'a'][x];
        }
        cout << f[x] << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
