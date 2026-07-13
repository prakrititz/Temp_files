class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int>dp(4000, 0);
        dp[1000] = 1;
        for(int i = 0;i<nums.size();i++)
        {
            vector<int>ndp(4000, 0);
            for(int j = -1000;j<=1000;j++)
            {
                if(j-nums[i] + 1000>=0)ndp[j+1000] += dp[j-nums[i]+1000];
                if(j+nums[i]+1000<4000)ndp[j+1000] += dp[j+nums[i]+1000];
            }
            dp = ndp;
        }
        return dp[target+1000];
    }
};