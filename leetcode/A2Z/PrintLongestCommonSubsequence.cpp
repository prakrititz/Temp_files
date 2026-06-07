#include<bits/stdc++.h>
using namespace std;
#define int long long 
    
string lcs(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<vector<string>>dp(n+1, vector<string>(m+1));
    dp[0][0] = "";
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(str1[i-1]==str2[j-1])dp[i][j] = str1[i-1] + dp[i-1][j-1];
            else{
                if(dp[i-1][j].size()>dp[i][j-1].size())
                {
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    reverse(dp[n][m].begin(), dp[n][m].end());
    return dp[n][m];
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        string str1, str2;
        cin>>str1>>str2;
        cout<<lcs(str1, str2)<<endl;
    }
    return 0;
}