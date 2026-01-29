#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    for(int j = 0;j<n;j++)cin>>b[j];
    int abig  = 0;
    int bbig = 0;
    for(int i = 0;i<n;i++)
    {
        if(a[i]>b[i])abig++;
        else if(a[i]<b[i])bbig++;
    }
    double awin = 
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