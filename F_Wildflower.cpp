#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void dfs(int node, vector<vector<int>> &grph, vector<int> &vis, vector<int> &dis, int curr_dis)
{
    vis[node] = true;
    dis[node] = curr_dis;
    for (auto it : grph[node])
    {
        if (!vis[it])
        {
            dfs(it, grph, vis, dis, curr_dis + 1);
        }
    }
}
long long modPow(long long base, long long exp)
{
    long long result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    int x, y;
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
        deg[x]++;
        deg[y]++;
    }
    int cnt = 0;
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1 && i != 0)
        {
            cnt++;
            t.push_back(i);
        }
    }
    if (cnt > 2)
    {
        cout << 0 << endl;
    }
    else
    {
        if (cnt == 1)
        {
            vector<int> vis(n);
            vector<int> dis(n);
            dfs(0, g, vis, dis, 1);
            int h = *max_element(dis.begin(), dis.end());
            cout << modPow(2, h) << endl;
        }
        else
        {
            vector<int> vis(n);
            vector<int> dis(n);
            dfs(0, g, vis, dis, 1);
            int hx = dis[t[0]];
            int hy = dis[t[1]];
            int v = 0;
            for (int i = 0; i < n; i++)
            {
                if (deg[i] == 3)
                {
                    v = i;
                    break;
                }
            }
            if (hx == hy)
            {
                cout << (modPow(2, dis[v]) * 2) % mod << endl;
            }
            else if (hx > hy)
            {
                cout << (((modPow(2, hx - hy) + modPow(2, hx - hy - 1)) % mod * modPow(2, dis[v]))) % mod << endl;
            }
            else
            {
                cout << (((modPow(2, hy - hx) + modPow(2, hy - hx - 1)) % mod * modPow(2, dis[v]))) % mod << endl;
            }
        }
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