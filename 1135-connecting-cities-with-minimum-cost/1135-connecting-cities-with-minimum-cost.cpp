class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {

        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto &e : connections) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        vector<int> vis(n + 1, 0);

        pq.push({0,1});

        int ans = 0;
        int cnt = 0;

        while(!pq.empty()) {

            auto [cost,node] = pq.top();
            pq.pop();

            if(vis[node]) continue;

            vis[node] = 1;
            ans += cost;
            cnt++;

            for(auto [next,w] : adj[node]) {
                if(!vis[next])
                    pq.push({w,next});
            }
        }

        return (cnt == n) ? ans : -1;
    }
};