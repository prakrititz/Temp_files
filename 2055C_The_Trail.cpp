#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        int L = n + m - 1;
        vector<pair<int, int>> path;
        int r = 0, c = 0;
        path.push_back({r, c});

        for (auto ch : s) {
            if (ch == 'D') r++;
            else c++;
            path.push_back({r, c});
        }

        vector<vector<long long>> grid(n, vector<long long>(m));
        vector<vector<bool>> onPath(n, vector<bool>(m, false));
        for (auto &p : path) onPath[p.first][p.second] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        vector<long long> fixedRow(n, 0), fixedCol(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!onPath[i][j]) {
                    fixedRow[i] += grid[i][j];
                    fixedCol[j] += grid[i][j];
                }
            }
        }

        int V = n + m;
        vector<long long> B(V, 0);
        for (int i = 0; i < n; i++) B[i] = -fixedRow[i];
        for (int j = 0; j < m; j++) B[n + j] = -fixedCol[j];

        int E = L;
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < L; i++) {
            auto pr = path[i];
            int u = pr.first, v = n + pr.second;
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }

        vector<int> deg(V, 0);
        for (int i = 0; i < V; i++) {
            deg[i] = adj[i].size();
        }

        vector<bool> usedEdge(E, false);
        vector<long long> edgeVal(E, 0);
        queue<int> qu;
        vector<bool> inQueue(V, false), removed(V, false);

        for (int i = 0; i < V; i++) {
            if (deg[i] == 1) {
                qu.push(i);
                inQueue[i] = true;
            }
        }

        while (!qu.empty()) {
            int u = qu.front();
            qu.pop();
            if (removed[u] || deg[u] == 0) continue;

            int nei = -1, eid = -1;
            for (auto &p : adj[u]) {
                if (!usedEdge[p.second]) {
                    nei = p.first;
                    eid = p.second;
                    break;
                }
            }

            if (eid == -1) continue;

            edgeVal[eid] = B[u];
            usedEdge[eid] = true;
            removed[u] = true;
            deg[u]--;
            deg[nei]--;
            B[nei] -= edgeVal[eid];

            if (deg[nei] == 1 && !removed[nei] && !inQueue[nei]) {
                qu.push(nei);
                inQueue[nei] = true;
            }
        }

        for (int i = 0; i < L; i++) {
            auto pr = path[i];
            grid[pr.first][pr.second] = edgeVal[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << (j + 1 == m ? "\n" : " ");
            }
        }
    }

    return 0;
}