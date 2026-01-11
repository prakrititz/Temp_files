#include<bits/stdc++.h>
using namespace std;
#define int long long 
// Problem Statement: Given an array containing both positive and negative integers, 
// we have to find the length of the longest subarray with the sum of all elements equal to zero.

int sum(vector<int>&a)
{
    int n = a.size();
    map<int, int>mp;
    mp[0] = -1;
    int s = 0;
    int len = 0;
    for(int i = 0;i<n;i++)
    {
        s += a[i];
        if(mp.find(s)!=mp.end()){
            len = max(len, i-mp[s]);
        }
        if(mp.find(s)==mp.end())mp[s] = i;
    }   
    return len;
}
void solve()
{   
    int  n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i++)cin>>a[i];
    cout<<sum(a)<<endl;
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