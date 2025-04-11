#include <bits/stdc++.h>
using namespace std;

void dfs(long long node, map<long long, long long> &vis, map<long long, vector<long long>> &mp, long long &max_val)
{
    vis[node] = 1;
    max_val = max(max_val, node);
    for (long long neighbor : mp[node])
    {
        if (!vis[neighbor + node])
        {
            dfs(neighbor + node, vis, mp, max_val);
        }
    }
}

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];

    map<long long, vector<long long>> mp;
    for (long long i = 0; i < n; i++)
    {
        long long val = a[i] + i;
        mp[val].push_back(i);
    }

    map<long long, long long> vis;

    // for (auto it : mp)
    // {
    //     cout << it.first << "->  ";
    //     for (long long id : it.second)
    //     {
    //         cout << id << " ";
    //     }
    //     cout << endl;
    // }
    long long max_val = n;
    for (auto it : mp)
    {
        if (it.first == n)
        {

            dfs(it.first, vis, mp, max_val);
        }
    }

    cout << max_val << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}