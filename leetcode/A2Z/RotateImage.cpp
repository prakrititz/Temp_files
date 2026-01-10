#include<bits/stdc++.h>
using namespace std;
#define int long long 
// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
void rotate(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        for(int j = 0;j<m; j++)
        {
            for(int i = j;i<n;i++)
            {
                swap(a[i][j], a[j][i]);
            }
        }
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m/2;j++){
                swap(a[i][j], a[i][m-1-j]);
            }
        }
}
void solve()
{
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>a(n, vector<int>(m));
    for(int i = 0;i<n; i++)
    {
        for(int j = 0;j<m;j++)
        cin>>a[i][j];
    }
    rotate(a);
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<m;j++)cout<<a[i][j]<<" ";
        cout<<endl;
    }
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