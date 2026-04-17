#include<bits/stdc++.h>
using namespace std;
#define int long long 

double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if(a.size()>b.size())return findMedianSortedArrays(b, a);
    int n = a.size();
    int m = b.size();
    int l = -1;int r = n-1;
    while(l<=r)
    {
        int mid = (l+r)/2;
        int k = (n+m)/2 - mid -2;
        int aL = (mid >= 0) ? a[mid] : INT_MIN;
        int aR = (mid + 1 < n) ? a[mid + 1] : INT_MAX;
        int bL = (k >= 0) ? b[k] : INT_MIN;
        int bR = (k + 1 < m) ? b[k + 1] : INT_MAX;
        if(aL>bR)
        {
            r = mid-1;
        }
        else if(bL>aR)
        {
            l = mid+1;
        }
        else{
            if((m+n)%2==0)
            {
                return (max(aL, bL)+min(aR, bR))/2.0;
            }
            else{
                return min(aR, bR);
            }
        }
    }
    return 0;
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