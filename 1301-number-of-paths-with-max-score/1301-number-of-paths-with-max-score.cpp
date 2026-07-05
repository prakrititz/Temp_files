class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9+7;
        vector<vector<int>>b(n);
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i==0 && j==0)b[i].push_back(0);
                else if( j==n-1 && i==n-1)b[i].push_back(0);
                else if(board[i][j]=='X')b[i].push_back(-1);
                else {
                    b[i].push_back((int)(board[i][j]-'0'));
                }
            }
        }
        for(auto it:b)
        {
            for(auto x:it)cout<<x<<" ";
            cout<<endl;
        }
        vector<vector<pair<int, int>>>dp(n, vector<pair<int, int>>(n));
        dp[n-1][n-1] = {0, 1};
        for(int i = n-1;i>=0;i--)
        {
            for(int j = n-1;j>=0;j--)
            {
                if(i==n-1 && j==n-1)continue;
                if(b[i][j]==-1)
                {
                    dp[i][j] = {-1, -1};
                }
                else{
                    int maxi = -1;
                    if(i+1<n)maxi = max(maxi, dp[i+1][j].first);
                    if(j+1<n)maxi = max(maxi, dp[i][j+1].first);
                    if(i+1<n && j+1<n)maxi = max(maxi, dp[i+1][j+1].first);
                    if(maxi==-1){
                        dp[i][j] = {-1, -1};
                    }
                    else{
                        int ways = 0;
                        if(i+1<n && maxi== dp[i+1][j].first) ways = (ways+dp[i+1][j].second)%mod;
                        if(j+1<n && maxi == dp[i][j+1].first)ways = (ways + dp[i][j+1].second)%mod;
                        if(j+1<n && i+1<n && dp[i+1][j+1].first==maxi)ways =(ways+dp[i+1][j+1].second)%mod;
                        dp[i][j] = {maxi+b[i][j], ways};
                    }
                }
            }
        }
        vector<int>ans;
        ans.push_back(dp[0][0].first);
        ans.push_back(dp[0][0].second);
        if(ans[1]==-1)return {0, 0};
        return ans;
    }
};