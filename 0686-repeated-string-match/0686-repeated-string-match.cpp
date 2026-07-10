class Solution {
public:
    long long mod = 1e9+7;
    long long modPow(int a, int n)
    {
        long long ans = 1;
        long long res = a;
        while(n)
        {
            if(n%2)
            {
                ans = (ans*res)%mod;
            }
            res = (res*res)%mod;
            n/=2;
        }
        return ans;
    }
    int repeatedStringMatch(string a, string b) {
        int cnt = 1;
        int size = a.size();
        string org =a;
        long long B = 26;
        long long bh = 0;
        for(int i = 0;i<b.size();i++)
        {
           bh = (B*bh + (long long)(b[i]-'a'))%mod; 
        }
        while(a.size()<b.size())
        {
            a += org;
            cnt++;
        }
        long long ah = 0;
        for(int i = 0;i<b.size();i++)
        {
            ah =  (B*(ah) + (long long)(a[i]-'a'))%mod; 
        }
        int en = b.size()-1;
        int st = 0;
        long long p = modPow(B, b.size() - 1);
        int slides = 0;
        while(true)
        {
            if(slides==size)break;
            if(ah == bh)
            {
                bool x = true;
                for(int j = 0;j<b.size();j++){
                    if(a[(j+st)%a.size()]!=b[j]){
                        x= false;
                        break;
                    }
                }
                if(x){
                    if(st + b.size()>a.size())return cnt+1;
                    return cnt;
                }
            }
            ah = (ah - ((a[st] - 'a') * p) % mod + mod) % mod;
            st = (st+1)%a.size();
            en = (en+1)%a.size();
            ah = (ah * B + (a[en] - 'a')) % mod;
            slides++;
        }
        return -1;
    }
};