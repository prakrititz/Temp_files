#include<bits/stdc++.h>
using namespace std;
#define int long double
void solve()
{   
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int p1 = a/b;
    int p2 = c/d;
    int ans = p1*(1/(1-(1-p1)*(1-p2)));
    cout<<fixed<<setprecision(12)<<ans<<endl;
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