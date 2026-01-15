#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int s, k, m;
    cin>>s>>k>>m;
    int dir = (m/k)%2;
    int rem;
    if(dir==0)
    {
        rem = s;
    }   
    else{
        rem = min(s,k);
    }
    cout<<max(rem-(m%k), 0LL)<<endl;
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