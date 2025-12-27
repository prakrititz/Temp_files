#include<bits/stdc++.h>
using namespace std;
#define int long long 
int longestConsecutiveSubsequence(vector<int>&a)
{

    // Input: nums = [100,4,200,1,3,2]
    // Output: 4
    // Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
    int n = a.size();
    map<int , int>mp;
    int maxi = INT_MIN;
    for(int i = 0;i<n ;i ++)
    {
        if(mp.find(a[i])==mp.end())
        {
            mp[a[i]] = 1 + mp[a[i-1]]+mp[a[i+1]];
        }
        maxi = max(maxi, mp[a[i]]);
    }
    return maxi;
}
void solve()
{ 
    //You must write an algorithm that runs in O(n) time.
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i =0;i<n;i++)cin>>a[i];  
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