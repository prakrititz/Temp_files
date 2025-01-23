#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    // Build adjacency list representation
    vector<vector<int>> graph(n+1);
    vector<int> degree(n+1, 0);
    
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    
    int max_components = 0;
    
    // Try removing each pair of vertices
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            
            // Calculate components after removing i and j
            vector<int> temp_degree = degree;
            
            // Subtract 1 from degrees of adjacent vertices to i
            for (int adj : graph[i]) {
                if (adj != j) temp_degree[adj]--;
            }
            
            // Subtract 1 from degrees of adjacent vertices to j
            for (int adj : graph[j]) {
                if (adj != i) temp_degree[adj]--;
            }
            
            // Count number of remaining components
            int components = 0;
            vector<bool> visited(n+1, false);
            visited[i] = visited[j] = true;
            
            for (int k = 1; k <= n; k++) {
                if (!visited[k]) {
                    components++;
                    queue<int> q;
                    q.push(k);
                    visited[k] = true;
                    
                    while (!q.empty()) {
                        int curr = q.front();
                        q.pop();
                        
                        for (int neighbor : graph[curr]) {
                            if (!visited[neighbor] && neighbor != i && neighbor != j) {
                                q.push(neighbor);
                                visited[neighbor] = true;
                            }
                        }
                    }
                }
            }
            
            max_components = max(max_components, components);
        }
    }
    
    cout << max_components << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}