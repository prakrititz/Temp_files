#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>> &grph, vector<int> &vis, vector<int> &dis) {
    vis[node] = true;
    int curr_dis = 1;
    for (auto it : grph[node]) {
        if (!vis[it] && it != parent) {
            curr_dis += dfs(it, node, grph, vis, dis);
        }
    }
    return dis[node] = curr_dis;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> edg(n + 1);
    vector<int> vis(n + 1, false);
    vector<int> dis(n + 1, 0);
    int t = n - 1;
    while (t--) {
        int u, v;
        cin >> u >> v;
        edg[u].push_back(v);
        edg[v].push_back(u);
    }
    
    if (n % 2 != 0) {
        cout << -1 << endl;
        return;
    }
    
    dfs(1, -1, edg, vis, dis);
    
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (dis[i] % 2 == 0) {
            count++;
        }
    }
    
    cout << count << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1; 
    // cin >> t; 
    
    while (t--) {
        solve();
    }
    
    return 0;
}