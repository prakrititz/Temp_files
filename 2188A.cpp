#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<int>mp(n+1, 0);
    a[n] = n;
    for(int i = n-1;i>=1;i--)
    {
        int x = abs(i+a[i+1]);
        int y = abs(i-a[i+1]);
        if(x>=1 && x<n && !mp[x])
        {
            a[i] = x;
            mp[x]++;
        }
        else if(y>=1 && y<n && !mp[y]) {
            a[i] = y;
            mp[y]++;
        }
    } 
    for(int i = 1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;  
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