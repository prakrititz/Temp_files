class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1)return a[0];
        int l = 0;int r = a.size()-1;
        int val = a[0];
        while(l<=r)
        {
            int m = (l+r)/2;
            if(m<a.size()-1 && a[m]==a[m+1])
            {
                if(m%2)r = m-1;
                else l = m+2;
            }
            else if(m>0 && a[m]==a[m-1])
            {
                if((m-1)%2)r=m-2;
                else l = m+1; 
            }
            else return a[m];
        }
        return val;
    }
};