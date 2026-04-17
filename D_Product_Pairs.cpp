#include<bits/stdc++.h>
using namespace std;
#define int long long
int maxn = 100000;
vector<int>ans(maxn+1, 0);
void precompute()
{
    vector<int> cnt(maxn + 2, 0);
    for(int x=2;x<=maxn+1;x++){
        int idx = x;
        for(int d = 2; d * d <= idx; d++) {
            while(idx % (d * d) == 0) {
                idx /= (d * d);
            }
        }
        ans[x-1] = 2*cnt[idx]+1;
        cnt[idx]++;
    }
    for(int i=1;i<=maxn;i++)ans[i]+=ans[i-1];
}
void solve()
{   
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    precompute();
    while(tc--)
    {
        solve();
    }
    return 0;
}