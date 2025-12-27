#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int l, a, b;
    cin>>l>>a>>b;
    map<int, int>mp;
    int maxi = a;
    while(mp[a]==0)
    {
        mp[a]++;
        a = (a+b)%l;
        maxi = max(maxi, a);
    }
    cout<<maxi<<endl;
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