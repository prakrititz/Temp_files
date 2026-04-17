#include<bits/stdc++.h>
using namespace std;
#define int long long 
vector<vector<int>>dp(100,vector<int>(100,0));
void precompute(){
    for(int i = 0;i<100;i++)dp[0][i] = 1;
    for(int i = 1;i<100;i++)
    {
        for(int h = 1;h<100;h++)
        {
            dp[i][h] = 0;
            for(int j = 0;j<i;j++)
            {
                dp[i][h] += dp[j][h-1]* dp[i-j-1][h-1];
            }
        }
    }    
}
void solve()
{
    int n, h;
    cin>>n>>h;
    cout<<dp[n][n] - dp[n][h-1]<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    precompute();
    while(tc--)
    {
        solve();
    }
    return 0;
}