#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>>c(2*n, vector<int>(2*n));
    for(int i = 0;i<2*n;i++)
    {
        for(int j = 0;j<2*n;j++)cin>>c[i][j];
    }   
    vector<pair<int, int>>v = {{0,2*n-1}, {0,n},{n,n-1},{n-1,n},{n-1,2*n-1},{n,0},{2*n-1,0},{2*n-1,n-1}};
    int sum = 0;
    for(int i = n;i<2*n;i++)
    {
        for(int j= n;j<2*n;j++)sum+=c[i][j];
    }
    int maxi = INT_MAX;
    for(auto it: v)
    {
        maxi = min(maxi, c[it.first][it.second]);
    }
    cout<<sum+maxi<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}