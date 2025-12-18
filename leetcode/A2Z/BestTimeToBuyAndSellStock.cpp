#include<bits/stdc++.h>
using namespace std;
#define int long long 
int maxProfit(vector<int>&a)
{
    int mini = a[0];
    int n = a.size();
    int maxi = 0;
    int cur = 0;
    for(int i = 1;i<n;i++)
    {
        cur = a[i]-mini;
        mini = min(mini, a[i]);
        maxi = max(maxi, cur);
    }
    return maxi;
}
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)
    {
        cin>>a[i];
    }   
    cout<<maxProfit(a)<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--)
    {
        solve();
    }
    return 0;
}