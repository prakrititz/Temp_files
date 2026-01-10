#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{  
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    int ans = 0;
    if(d%2)d--;
    ans += d/2;
    if(a%2==0 && b%2==0 && c%2==0)
    {
        ans += (a+b+c)/2;
    }
    else if(a%2==1 && b%2==1 && c%2==1)
    {
        ans += (a+b+c-1)/2;
    }
    else if((a%2+b%2+c%2)==1)
    {
        ans += (a+b+c-1)/2;
    }
    else {
        ans += (a+b+c-2)/2;
    }
    cout<<ans<<endl;
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