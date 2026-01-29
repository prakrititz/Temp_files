#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    int ans = 1;
    for(int i=1;i<=12;i++)
    {
        int idx = rng() % n;
        vector<int>divisors;
        for(int j = 1;j*j<=a[idx];j++)
        {
            if(a[idx]%j==0)
            {
                divisors.push_back(a[idx]/j);
                divisors.push_back(j);
            }
        }
        sort(divisors.rbegin(), divisors.rend());
        vector<int>x(n);
        for(int j = 0;j<n;j++)
        {
            x[j] = gcd(a[j], a[idx]);
        }
        unordered_map<int, int>mp;
        for(auto it: x){
            mp[it]++;
        }
        for(auto d:divisors)
        {
            int cnt = 0;
            for(auto it: mp)
            {
                if(it.first%d==0)
                {
                    cnt += it.second;
                }
            }
            if(cnt>=(n+1)/2)
            {
                ans = max(d,ans);
                break;
            }
        }
    }
    cout<<ans<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}