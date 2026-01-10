#include<bits/stdc++.h>
using namespace std;
#define int long long 
class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        bool t = false;
        bool f = false;
        for(int i = 0;i<n;i++)if(a[i][0]==0)f = true;
        for(int i = 0;i<m;i++)if(a[0][i]==0)t = true;
        for(int i = 1;i<n;i++)
        {
            for(int j = 1;j<m;j++)
            {
                if(a[i][j]==0)
                {
                    a[0][j] = 0;
                    a[i][0] = 0;
                }
            }
        }
        for(int i = 1;i<n;i++)
        {
            if(a[i][0]==0)
            {
                for(int j = 0;j<m;j++)a[i][j] = 0;
            }
        }
        for(int i = 1;i<m;i++)
        {
            if(a[0][i]==0)
            {
                for(int j = 0;j<n;j++)a[j][i] = 0;
            }
        }
        if(f)for(int i = 0;i<n;i++)a[i][0]=0;
        if(t)for(int j = 0;j<m;j++)a[0][j] = 0;
    }
};
void solve()
{   
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