#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    map<int, int> need = {{0, 3}, {1, 1}, {3, 1}, {2, 2}, {5, 1}};
    int ans = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {

        if (need.count(a[i]) && need[a[i]] > 0)
        {
            need[a[i]]--;
        }
        ans++;

        bool completed = true;
        for (auto it : need)
        {
            if (it.second > 0)
            {
                completed = false;
                break;
            }
        }

        if (completed)
        {
            cout << ans << endl;
            return;
        }
    }

    cout << 0 << endl;
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
