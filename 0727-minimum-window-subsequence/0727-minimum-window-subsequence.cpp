class Solution {
public:
    string minWindow(string s1, string s2) {
        int i = 0;
        int n =  s1.size();
        int m =s2.size();
        int l = -1;
        int r = -1;
        int minLen = INT_MAX;
        for(int j = 0;j<n;j++)
        {
            if(s1[j]!=s2[i])continue;
            if(s1[j]==s2[i])
            {
                i++;
            }
            if(i==m)
            {
                int cur_j = j;
                int cur_i = i-1;
                while(cur_i>=0)
                {
                    if(s1[cur_j]!=s2[cur_i])
                    {
                        cur_j--;
                    }
                    else{
                        cur_i--;
                        cur_j--;
                    }
                }
                int len = (j-cur_j);
                if(len<minLen)
                {
                    minLen = len;
                    l = cur_j+1;
                    r = j;
                }
                i = 0;
                j = cur_j+1;
            }
        }
        if(l == -1)return "";
        return s1.substr(l, r-l+1);
    }
};