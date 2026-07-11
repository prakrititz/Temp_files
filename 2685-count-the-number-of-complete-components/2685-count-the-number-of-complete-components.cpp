class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n, 0);
        int ans = 0;
        for(int i = 0;i<n ;i++)
        {
            queue<int>q;
            if(!vis[i])
            {
                int edge_cnt = 0;
                int node_cnt = 0;
                q.push(i);
                vis[i] = 1;
                while(!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    node_cnt ++;
                    for(auto it:adj[u])
                    {
                        edge_cnt++;
                        if(!vis[it])
                        {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
                edge_cnt/=2;
                cout<<node_cnt<<" "<<edge_cnt<<endl;
                int required = ((node_cnt)*(node_cnt-1))/2;
                if(edge_cnt == required)ans++;
            }
        }
        return ans;
    }
};