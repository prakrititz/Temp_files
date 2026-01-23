#include<bits/stdc++.h>
using namespace std;
#define int long long 
// lower bound returns index that is greater or equal to what the value is asked
//upper bound returns index that is strictly greater 
int lowerBound(vector<int>&a, int target)
{
    int l = 0;
    int r = a.size()-1;
    int ans = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid]>=target)//greter equal
        {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return ans;
}

int upperBound(vector<int>&a, int target)
{
    int l = 0;
    int r = a.size()-1;
    int ans = -1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        if(a[mid]>target)//strictly greater
        {
            ans = mid;
            r = mid-1;
        }
        else {
            l = mid+1;
        }
    }
    return ans;
}
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