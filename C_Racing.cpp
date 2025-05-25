#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++)
        cin >> d[i];
    vector<pair<int, int>> r;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        r.emplace_back(x, y);
    }
    int mn = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        if (d[i] == -1)
            mx++;
        else
        {
            mx += d[i];
            mn += d[i];
        }
        if (mn > r[i].second || mx < r[i].first)
        {
            cout << -1 << endl;
            return;
        }
        mn = max(mn, r[i].first);
        mx = min(mx, r[i].second);
    }
    if (mn > mx)
    {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(n, 0);
    int curr = 0;
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (d[i] != -1)
        {
            curr += d[i];
            ans[i] = d[i];
        }
        else
        {
            st.push(i);
        }
        while (curr < r[i].first)
        {
            if (st.empty())
            {
                cout << -1 << endl;
                return;
            }
            int id = st.top();
            curr++;
            ans[id]++;
            st.pop();
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
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