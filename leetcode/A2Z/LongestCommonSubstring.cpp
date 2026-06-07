#include <bits/stdc++.h>
using namespace std;

    class Solution {
      public:
        int longCommSubstr(string& str1, string& str2) {
            // code here
            int  n= str1.size();
            int  m = str2.size();
            vector<vector<int>>dp(n+1, vector<int>(m+1));
            dp[0][0] = 0;
            for(int i = 1;i<=n;i++)
            {
                for(int j = 1;j<=m;j++)
                {
                    if(str1[i-1]==str2[j-1])
                    {
                        dp[i][j] = 1+dp[i-1][j-1];
                        if(i>1 && j>1 && str1[i-2]!=str2[j-2])dp[i][j] = 1;
                    }
                    else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            int ans = 0;
            for(int i = 1;i<=n;i++)
            {
                for(int j = 1;j<=m;j++)
                {
                    ans= max(ans,dp[i][j]);
                }
            }
            return ans;
        }
    };

int main() {
string s1 = "ACDGHR";

string s2 = "ABCDGH";

    // Create an instance of Solution class
    Solution sol;
    
    // Print the result
    cout << "The Length of Longest Common Substring is " << sol.longestCommonSubstr(s1, s2) << endl;

    return 0;
}