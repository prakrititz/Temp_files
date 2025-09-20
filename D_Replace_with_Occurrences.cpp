#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];

    map<int, vector<int>> pos;
    for (int i = 0; i < n; i++)
    {
        pos[b[i]].push_back(i);
    }

    vector<int> a(n, -1);
    int cur = 1;
    bool ok = true;

    for (auto &[k, ind] : pos)
    {
        if ((int)ind.size() % k != 0)
        {
            ok = false;
            break;
        }
        for (int i = 0; i < (int)ind.size(); i += k)
        {
            for (int j = 0; j < k; j++)
            {
                a[ind[i + j]] = cur;
            }
            cur++;
        }
    }

    if (!ok)
    {
        cout << -1 << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
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