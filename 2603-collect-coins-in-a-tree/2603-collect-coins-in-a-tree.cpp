class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();

        vector<vector<int>> g(n);
        vector<int> deg(n);

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        vector<int> removed(n, 0);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1 && coins[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            removed[u] = 1;

            for (int v : g[u]) {
                if (removed[v]) continue;

                deg[v]--;

                if (deg[v] == 1 && coins[v] == 0)
                    q.push(v);
            }
        }
        queue<int> leaves;

        for (int i = 0; i < n; i++) {
            if (!removed[i] && deg[i] == 1)
                leaves.push(i);
        }

        for (int round = 0; round < 2; round++) {
            int sz = leaves.size();

            while (sz--) {
                int u = leaves.front();
                leaves.pop();

                removed[u] = 1;

                for (int v : g[u]) {
                    if (removed[v]) continue;

                    deg[v]--;

                    if (deg[v] == 1)
                        leaves.push(v);
                }
            }
        }

        int remainingEdges = 0;

        for (auto &e : edges) {
            if (!removed[e[0]] && !removed[e[1]])
                remainingEdges++;
        }

        return remainingEdges * 2;
    }
};