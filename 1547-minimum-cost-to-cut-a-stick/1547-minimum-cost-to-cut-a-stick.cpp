class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end()); 
    vector<vector<int>>dp(cuts.size(), vector<int>(cuts.size()));
    for(int i = 0;i<dp.size();i++)dp[i][i] = 0;
    int s = cuts.size();
    for(int r = 0;r<s;r++)
    {
        for(int l = r-2;l>=0;l--)
        {
            dp[l][r] = INT_MAX;
            for(int i = r-1;i>l;i--)
            {
                int len = cuts[r]-cuts[l];
                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i][r] + len);
            }
        }
    }
    return dp[0][s-1];    
    }
};