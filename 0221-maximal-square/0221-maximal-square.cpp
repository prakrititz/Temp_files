class Solution {
public:
    int maximalSquare(vector<vector<char>>&a) {
        int m = a.size();
        int n = a[0].size();
        vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                int x = (a[i-1][j-1]=='1') ? 1:0;
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1]+x;
            }
        }
        for(int i = 1;i<=m;i++)
        {
            for(int j = 1;j<=n;j++)
            {
                for(int l = 1;l<= min(i, j);l++)
                {
                    if(l*l==dp[i][j]-dp[i-l][j]-dp[i][j-l] + dp[i-l][j-l])ans = max(ans, l*l);
                }
            }
        } 
        return ans;
    }
};