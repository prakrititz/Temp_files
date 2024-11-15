#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> color(n + 1, -1);
    vector<int> group[2]; 
    queue<int> q;
    q.push(1);
    color[1] = 0;
    group[0].push_back(1);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (int u : adj[v]) {
            if (color[u] == -1) {
                color[u] = 1 - color[v];
                group[color[u]].push_back(u);
                q.push(u);
            }
        }
    }
    int chosen_color = (group[0].size() <= group[1].size() ? 0 : 1);
    
    cout << group[chosen_color].size() << "\n";
    for (int i = 0; i < group[chosen_color].size(); i++) {
        cout << group[chosen_color][i] << (i == group[chosen_color].size() - 1 ? "\n" : " ");
    }

    }
    return 0;
}
