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
                if(a[i-1][j-1]=='1')
                {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
                }
                else{
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]*dp[i][j]);
            }
        }
        for(auto it:dp)
        {
            for(auto x:it)cout<<x<<" ";
            cout<<endl;
        }
        return ans;
    }
};