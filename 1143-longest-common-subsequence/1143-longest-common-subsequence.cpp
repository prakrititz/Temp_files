class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        vector<vector<int>>dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = 1;i<=s1.size();i++)
        {
            for(int j = 1;j<=s2.size();j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string res ="";
        int i = s1.size();
        int j = s2.size();
        while(i>0 && j>0)
        {
            if(s1[i-1]==s2[j-1])
            {
                res += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                i--;
            }
            else{
                j--;
            }
        }
        reverse(res.begin(), res.end());
        cout<<res<<endl;
        return dp[s1.size()][s2.size()];
    }
};