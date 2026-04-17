#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool check(vector<int>&a, int k, int dist)
{   
    int cnt = 1;
    int cur = a[0];
    for(int i = 1;i<a.size();i++)
    {   
        if(a[i]-cur>=dist)
        {
            cnt++;
            cur = a[i];
        }
    }
    return cnt>=k;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    int lo = 0;
    int hi = a[n-1]-a[0];
    int ans = lo;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(check(a,k, mid))
        {
            ans = mid;
            lo = mid+1; 
        }
        else{
            hi = mid-1;
        }
    }
    cout<<ans<<endl;
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