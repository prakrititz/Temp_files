#include<bits/stdc++.h>
using namespace std;
#define int long long 
// Subarray Sum Equals K
int subarraySum(vector<int>& a, int k) {
    int n =a.size();
    map<int, int>mp;
    int sum = 0;
    int ans = 0;
    mp[0] = 1;
    for(int i= 0;i<n ;i++)
    {   
        sum += a[i];
        if(mp.find(sum-k)!=mp.end()){
            ans += mp[sum-k];
        }
        mp[sum]++;
    }
    return ans;
}
void solve()
{   
    int n , k;
    cin>>n>>k;
    vector<int>a(n);
    for(int i =0;i<n;i++)cin>>a[i];
    cout<<subarraySum(a, k)<<endl;
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