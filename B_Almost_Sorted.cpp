#include<bits/stdc++.h>
using namespace std;
#define int long long 
int pow(int x, int n) {
    if (n >= 62) return LONG_LONG_MAX;
    int ans = 1; 
    while (n > 0) {        
        if (n % 2 != 0) {
            ans = ans * x; 
        }
        x = x * x; 
        n = n / 2; 
    }
    return ans;
}
void solve()
{   
    int n ,k;
    cin>>n>>k;
    vector<int>ans(n,0);
    if(pow(2, n-1)<k){
        cout<<-1<<endl;
        return;
    }
    else if(pow(2, n-1)==k)
    {   
        for(int i = 1;i<=n;i++)cout<<n-i+1<<" ";
        cout<<endl;
        return;
    }
    else {
        k--;
        int i = 1;
        int first = 0;
        int curr = 1;
        ans[0] = curr;
        while(i<n)
        {
            int size = max(n-1-i,0LL);
            if(k>=pow(2,size))
            {
                k-= pow(2, size);
                curr++;
            }
            else{
                for(int j = first;j<i;j++){
                    ans[j] = curr;
                    curr--;
                }
                first = i;
                curr = i+1;
            }
            i++;
        }
        for(int j = first;j<i;j++){
        ans[j] = curr;
        curr--;
        }
        for(auto it: ans)cout<<it<<" ";
        cout<<endl;
    }
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