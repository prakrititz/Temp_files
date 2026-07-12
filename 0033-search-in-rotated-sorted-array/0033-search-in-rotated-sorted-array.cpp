class Solution {
public:
    int search(vector<int>& a, int val) {
        // we need to find k first
        int n = a.size();
        int l = 0;
        int r = n-1;
        int k = 0;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(a[m]==val)return m;
            if(a[m]<=a[r])
            {
                if(val<=a[r] && val>=a[m])
                {
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
            else{
                if(val>=a[l] && val<=a[m])
                {
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
        }
        return -1;
    }
};