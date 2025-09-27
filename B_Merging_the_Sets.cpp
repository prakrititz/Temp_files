#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m);
    vector<vector<int>> s(n);
    for (int i = 0; i < n; i++)
    {
        int sze;
        cin >> sze;
        s[i].resize(sze);
        for (int j = 0; j < sze; j++)
        {
            cin >> s[i][j];
            s[i][j]--;
            cnt[s[i][j]]++;
        }
    }
    if (count(cnt.begin(), cnt.end(), 0))
    {
        cout << "NO" << endl;
        return;
    }
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        for (auto x : s[i])
        {
            if (cnt[x] == 1)
            {
                ok = false;
            }
        }
        ans += ok;
    }
    if (ans >= 3)
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