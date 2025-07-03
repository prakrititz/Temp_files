#include <bits/stdc++.h>
using namespace std;
void bfs(int start, vector<vector<int>> &grph, vector<int> &dis)
{
    queue<int> q;
    vector<bool> vis(grph.size(), false);
    q.push(start);
    vis[start] = true;
    dis[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto it : grph[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                dis[it] = dis[node] + 1;
                q.push(it);
            }
        }
    }
}

void solve()
{
    int n, k, c;
    cin >> n >> k >> c;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> d0(n),d1(n),d2(n);
    bfs(0, adj, d0);
    int s = max_element(d0.begin(), d0.end()) - d0.begin();
    bfs(s,adj,d1);
    int t = max_element(d1.begin(), d1.end()) - d1.begin();
    bfs(t,adj,d2);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, 1LL *k*max(d1[i], d2[i]) - 1LL * c * d0[i]);
    }
    cout << ans << endl;
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