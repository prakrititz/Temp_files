class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        for(int i = 0;i<3;i++)dp[0][1][i] = -1e9;
        for(int i = 1;i<=n;i++)
        {
            for(int cnt = 1;cnt<3;cnt++)
            {
                dp[i][0][cnt] = max(dp[i-1][0][cnt], dp[i-1][1][cnt] + price[i-1]);
                dp[i][1][cnt] = max(dp[i-1][1][cnt], dp[i-1][0][cnt-1] - price[i-1]);
            }
        }
        return dp[n][0][2];
    }
};