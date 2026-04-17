#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool check(vector<int>&a, int k, int total)
{   
    int cur = 0;
    int cnt = 0;
    for(int i = 0;i<a.size();i++)
    {   
        if(a[i] > total) return false;
        if(cur+a[i]<=total)
        {
            cur += a[i];
        }
        else{
            cnt ++;
            cur = a[i];
        }
    }
    if(cur>0)cnt++;
    return cnt<=k;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    int lo = 0;
    int hi = accumulate(a.begin(), a.end(), 0l);
    int ans = lo;
    while(lo<=hi)
    {
        int mid = (lo+hi)/2;
        if(check(a,k, mid))
        {
            ans = mid;
            hi = mid-1; 
        }
        else{
            lo = mid+1;
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