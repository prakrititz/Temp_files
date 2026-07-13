class Solution {
public:
    int maxCoins(vector<int>& nums){
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>>dp(nums.size(), vector<int>(nums.size(),0));
    for(int l = nums.size()-1;l>=0;l--)
    {
        for(int r = l+2;r<nums.size();r++)
        {
            for(int i = l+1;i<r;i++)
            {
                dp[l][r] = max(nums[i]*nums[r]*nums[l] + dp[l][i] + dp[i][r], dp[l][r]);
            }
        }
    }
    return dp[0][nums.size()-1];
}
};