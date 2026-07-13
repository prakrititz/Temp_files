class Solution {
public:
    bool canPartition(vector<int>& arr) {
        int n = arr.size();
        int K = (accumulate(arr.begin(), arr.end(), 0));
        if(K%2)return false;
        vector<bool>dp(K+1, 0);
        dp[0] = 1;
        for(int i = 0;i<n;i++)
        {
            vector<bool>ndp = dp;
            for(int t = 0;t<K;t++)
            {
                int y = 0;
                if(t-arr[i]>=0)y = dp[t-arr[i]];
                int x = dp[t];
                ndp[t] = x|y;
            }
            dp = ndp;
        }
        for(auto it:dp)cout<<it<<" ";
        cout<<endl;
        return dp[K/2];
    }
};