class Solution {
public:
    int minCut(string s) {
        int n= s.size();
        vector<int>dp(n, 1e9);   
        vector<vector<int>>p(n, vector<int>(n, 0));
        for (int r = 0; r < n; r++) {
            for (int l = 0; l <= r; l++) {
                if (s[l] == s[r] && (r - l <= 2 || p[l + 1][r - 1])) {
                    p[l][r] = 1;
                }
            }
        }
        for(int i = n-1;i>=0;i--)
        {
            for(int k = i;k<n;k++)
            {
                if(p[i][k]){

                    if(k<n-1)dp[i] = min(dp[k+1]+1, dp[i]);
                    else dp[i] = 0;
                }
            }
        }
        return dp[0];
    }
};