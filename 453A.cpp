#include<bits/stdc++.h>
using namespace std;
#define int long long 
long double power(long double m, int n)
{
    long double ans = 1;
    while(n>0)
    {
        if(n%2)ans*=m;
        m*=m;
        n/=2;
    }
    return ans; 
}
void solve()
{
    int n;
    long double m;
    cin>>m>>n;
    long double ans = 0;
    long double val = 0;
    for(long double i = 1;i<=m;i++)
    {
        long double val1 = power(i/m, n);
        ans += i*(val1-val);
        val = val1;
    }
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