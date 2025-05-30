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
    int a, b, c;
    cin >> a >> b >> c;
    int n = a + b + c;
    vector<vector<int>> adj(n);
    int curr = 0;
    queue<int> q;
    for (int i = 0; i < c; i++)
    {
        q.push(curr);
        curr++;
    }
    while (b--)
    {
        if (q.empty())
        {
            cout << -1 << endl;
            return;
        }
        int u = q.front();
        q.pop();
        int v = curr;
        adj[u].push_back(v);
        adj[v].push_back(u);
        q.push(curr);
        curr++;
    }
    while (a--)
    {
        if (q.size() < 2)
        {
            cout << -1 << endl;
            return;
        }
        int u1 = q.front();
        q.pop();
        int u2 = q.front();
        q.pop();
        int v = curr;
        adj[curr].push_back(u1);
        adj[curr].push_back(u2);
        adj[u1].push_back(curr);
        adj[u2].push_back(curr);
        q.push(curr);
        curr++;
    }
    curr--;
    vector<int> dis(n, INT_MAX);
    bfs(curr, adj, dis);
    int maxi = *max_element(dis.begin(), dis.end());
    if (maxi == INT_MAX)
        cout << -1 << endl;
    else
        cout << maxi << endl;
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