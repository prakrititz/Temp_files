class Solution {
public:
    int mod = 1e9+7;
    long long power(int n){
        long long res  = 10;
        long long ans = 1;
        while(n)
        {
            if(n%2)ans = (ans*res)%mod;
            n/=2;
            res = (res*res)%mod;
        }
        return ans;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        string p = "";
        vector<int>v;
        vector<int>v2;
        int n =s.size();
        for(int i = 0;i<n ;i++)
        {
            if(s[i]!='0'){
                p += s[i];
                v.push_back(i);
                v2.push_back(s[i]-'0');
            }
        }
        vector<long long>pre(v.size()+1, 0);
        for(int i = 1;i<v.size()+1;i++)
        {
            pre[i] = v2[i-1]+pre[i-1];
        }
        vector<long long>pref(v.size()+1, 0);
        for(int i = 1;i<v.size()+1;i++)
        {
            pref[i] = (pref[i-1] * 10 + v2[i-1])%mod;
        }
        vector<int>ans;
        for(auto it:queries)
        {
            int l = it[0];
            int r = it[1];
            int vl = (int)(lower_bound(v.begin(), v.end(), l)-v.begin());
            if(vl>=n){
                ans.push_back(0);
                continue;
            }     
            int lo = 0;
            int hi = v.size()-1;
            int vr = -1;
            while(lo<=hi)
            {
                int mid =(lo+hi)/2;
                if(v[mid]<=r)
                {
                    vr = mid;
                    lo = mid+1;
                }
                else{
                    hi = mid-1;
                }
            }   
            cout<<vl<<" "<<vr<<endl;
            long long deci = power((vr-vl+1));
            int t = ((pref[vr+1]-(pref[vl]*deci)%mod+mod)%mod * (pre[vr+1]-pre[vl]+mod))%mod;
            ans.push_back(t);
        }
        return ans;
    }
};