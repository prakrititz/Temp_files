class Solution {
public:
    vector<pair<int, int>>dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int dfs(vector<vector<int>>&g, int i, int j,vector<vector<int>>&dp)
    {
        int n = g.size();
        int m = g[0].size();
        if(!(i<n && i>=0 && j<m && j>=0))return 0;
        if(dp[i][j]!=-1){   
            return dp[i][j];
        }
        int maxi = 0;
        int val = g[i][j];
        for(auto it: dir){
            int ni = i+it.first;
            int nj = j + it.second;
            if(ni<n && nj<m && ni>=0 && nj>=0 && val< g[ni][nj]){
                maxi = max(dfs(g, ni, nj, dp), maxi);
            }
        }
        return dp[i][j] = 1 + maxi;        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                ans = max(ans, dfs(matrix, i, j, dp));
            }
        }
        return ans;    
    }
};