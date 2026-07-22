class Solution {
public:
    const int mod = 1e9+7;
    // this is directly KMP alogirht
    string longestPrefix(string s) {
        int n =s.size();
        vector<int>dp(s.size(), 0);
        int i = 1;
        int len = 0;
        while(i<n)
        {
            if(s[i]==s[len])
            {
                len++;
                dp[i] = len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    dp[i] = 0;
                    i++;
                }
                else{
                    len = dp[len-1];
                }
            }
        }
        return s.substr(0, dp[n-1]);
    }
};