class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if(a.size()>b.size())return findMedianSortedArrays(b, a);
    int n = a.size();
    int m = b.size();
    int l = 0;int r = n;
    while(l<=r)
    {
        int mid = (l+r)/2; // no of elements
        int k = (n+m+1)/2 - mid;
        int aL = (mid-1>=0) ? a[mid-1] : INT_MIN;
        int bL = (k-1>=0) ? b[k-1] : INT_MIN;
        int aR = (mid<n) ? a[mid] : INT_MAX;
        int bR = (k<m) ? b[k] : INT_MAX;
        if(aL>bR)
        {
            r = mid-1;
        }
        else if(bL>aR)
        {
            l = mid+1;
        }
        else 
        {
           if ((n+m)%2)
                return max(aL, bL);
            else
                return (max(aL,bL) + min(aR,bR)) / 2.0;
        }
    }
    return 0;
}
};