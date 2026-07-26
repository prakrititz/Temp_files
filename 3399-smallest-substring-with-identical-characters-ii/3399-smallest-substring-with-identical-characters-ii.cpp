class Solution {
public:
    bool check(string s, int k, int m)
    {
        int n = s.size();
        if (m == 1) {
                int diff1 = 0, diff2 = 0;
                for (int i = 0; i < n; i++) {
                    char expected1 = (i % 2 == 0) ? '0' : '1';
                    char expected2 = (i % 2 == 0) ? '1' : '0';
                    if (s[i] != expected1) diff1++;
                    if (s[i] != expected2) diff2++;
                }
                return min(diff1, diff2) <= k;
            }
        int cnt = 0;
        int i = 0;
        int j = i+1;
        while(i<n && j<n)
        {
            int len = (j-i+1);
            if(s[i]==s[j])
            {
                if(len>m)
                {
                    i = j+1;
                    cnt++;
                    continue;
                }
                else{
                    j++;
                }
            }
            else{
                i = j;
            }
        }
        cout<<cnt<<" "<<m<<endl;
        return cnt<=k;
    }
    int minLength(string s, int numOps) {
        int  l = 1;
        int r = s.size();
        int ans = r;
        while(l<=r)
        {
            int m = (l+r)/2;
            if(check(s, numOps, m))
            {
                ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        return ans;
    }
};