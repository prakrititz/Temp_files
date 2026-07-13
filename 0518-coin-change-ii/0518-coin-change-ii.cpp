class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<long long>>dp(n, vector<long long>(amount+1));
        // for(int i = 0;i<n;i++)dp[i][0] = 1;
        // for(int i = 1;i<=amount ;i++)
        // {
        //     for(int j = 0;j<n;j++)
        //     {
        //         unsigned int take = 0;
        //         unsigned int not_take = 0;
        //         if(j>0)not_take = dp[j-1][i];
        //         if(i-coins[j]>=0)take = dp[j][i-coins[j]];
        //         dp[j][i] = take+not_take; 
        //     }
        // }
        // return dp[n-1][amount];
        vector<long long>dp(amount+1);
        dp[0] =1;
        long long inf = INT_MAX;
        for(auto it:coins)
        {
            for(int j = 1;j<=amount;j++)
            {
                if(j-it>=0)dp[j] = min(dp[j-it]+dp[j],inf);
            }
        }
        if(dp[amount]==INT_MAX)return 0;
        return dp[amount];
    }
};