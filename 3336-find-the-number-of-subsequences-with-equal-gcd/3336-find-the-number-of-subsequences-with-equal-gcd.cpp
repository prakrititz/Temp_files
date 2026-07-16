class Solution {
public:
    int mod = 1e9+7;
    int subsequencePairCount(vector<int>& nums) {
        int x = *max_element(nums.begin(), nums.end());
        vector<vector<vector<int>>>dp(nums.size()+1, vector<vector<int>>(x+1, vector<int>(x+1)));

        vector<vector<int>>gd(x+1, vector<int>(x+1));
        for(int i = 0;i<=x;i++)
        {
            for(int j = 0;j<=x;j++)gd[i][j] = gcd(i, j);
        }
        dp[0][0][0] = 1;
        for(int i = 1;i<=nums.size();i++)
        {
            for(int j = 0;j<=x;j++)
            {
                for(int k = 0;k<=x;k++)
                {
                    dp[i][j][k] = (dp[i-1][j][k] + dp[i][j][k])%mod;
                    dp[i][gd[j][nums[i-1]]][k] = (dp[i-1][j][k] + dp[i][gd[j][nums[i-1]]][k])%mod;
                    dp[i][j][gd[nums[i-1]][k]] = (dp[i-1][j][k] + dp[i][j][gd[nums[i-1]][k]])%mod; 
                }
            }
        }
        int ans =0;
        for(int i = 1;i<=x;i++) ans = (ans + dp[nums.size()][i][i])%mod;
        return ans;

    }

};