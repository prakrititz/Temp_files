#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<int> &visited, int &count) {
    visited[node] = count;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited, count);
        }
    }
}

int numberOfConnectedComponents(int n, vector<pair<int, int>> &edges, vector<int>&visited) {
    vector<vector<int>> adjList(n);
    for (auto &edge : edges) {
        adjList[edge.first].push_back(edge.second);
        adjList[edge.second].push_back(edge.first);
    }
    int components = 0;
    int count = 1;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adjList, visited, count);
            components++;
            count++;
        }
    }
    return components;
}

int modified(int n, vector<pair<int, int>> &F, vector<int>&visitedG) {
    vector<vector<int>> adjList(n);
    for(int i = 0; i < F.size(); i++) {
        if(visitedG[F[i].first]==visitedG[F[i].second]) {
            adjList[F[i].first].push_back(F[i].second);
            adjList[F[i].second].push_back(F[i].first);
        }
    }
    
    vector<int>visited(n, 0);
    int components = 0;
    int count = 1;
    
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, adjList, visited, count);
            components++;
            count++;
        }
    }
    return components;
}

void solve() {
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> F, G;
    for (int i = 0; i < m1; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        F.emplace_back(x, y);
    }
    
    for (int i = 0; i < m2; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        G.emplace_back(x, y);
    }
    vector<int> visitedG(n, 0);
    int componentsG = numberOfConnectedComponents(n, G, visitedG);
    int count = 0;
    for(int i = 0; i < m1; i++) {
        if(visitedG[F[i].first]!=visitedG[F[i].second]) {
            count++;
        }
    }
    int x = modified(n, F, visitedG);
    int ans = count + x - componentsG;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}