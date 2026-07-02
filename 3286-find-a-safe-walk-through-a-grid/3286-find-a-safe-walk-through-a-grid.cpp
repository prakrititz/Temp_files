class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, -1));
        queue<vector<int>>q;
        q.push({0, 0, health-grid[0][0]});
        vector<pair<int, int>>dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty())
        {
            int i = q.front()[0];
            int j = q.front()[1];
            int curr_health = q.front()[2];
            q.pop();
            for(auto it:dir)
            {
                int ni = i + it.first;
                int nj = j + it.second;
                if(ni<n && nj<m && ni>=0 && nj>=0 && vis[ni][nj]<(curr_health-grid[ni][nj]) && (curr_health-grid[ni][nj])>0)
                {
                    q.push({ni, nj, curr_health-grid[ni][nj]});
                    vis[ni][nj] = curr_health-grid[ni][nj];
                }
            }
        }
        if(vis[n-1][m-1]>=1)return true;
        return false;
    }
};