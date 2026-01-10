#include<bits/stdc++.h>
using namespace std;
#define int long long 
void push(vector<vector<int>>&a, vector<vector<int>>&m, vector<int>&ans, int s, int t, int x, int y)
{
    if(s>=a.size() || t>=a[0].size() || x<0 || y<0)return; 
    if(m[s][t]==1)return;
    if(x==s && t==y)
    {
        ans.push_back(a[x][y]);
        return;
    }
    for(int i = t;i<=y;i++){
        if(m[s][i]==0)
        {
        ans.push_back(a[s][i]);
        m[s][i]++;
        }
    }
    for(int i = s;i<=x;i++){
        if(m[i][y]==0)
        {
        ans.push_back(a[i][y]);
        m[i][y]++;
        }
    }
    for(int i = y;i>=t;i--){
        if(m[x][i]==0)
        {
        ans.push_back(a[x][i]);
        m[x][i]++;
        }
    }
    for(int i = x;i>=s;i--){
        if(m[i][t]==0)
        {
        ans.push_back(a[i][t]);
        m[i][t]++;
        }
    }
    push(a, m, ans, s+1, t+1, x-1, y-1);

}
vector<int> spiralOrder(vector<vector<int>>& a) {
    int n = a.size();
    int m = a[0].size();
    vector<int>ans;
    vector<vector<int>>mp(n, vector<int>(m, 0));
    push(a,mp,ans, 0, 0, n-1, m-1);
}
void solve()
{   
    int n, m;
    cin>>n>>m;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)cin>>a[i][j];
    }
    spiralOrder(a);
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