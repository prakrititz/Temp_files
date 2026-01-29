#include<bits/stdc++.h>
using namespace std;
#define int long long
void ans(int x, int y)
{
    if(y>x)ans(y, x);
    cout<<x<<" "<<(0^(x&&y))<<endl;
} 
void solve()
{
    int x, y;
    cin>>x>>y;
    if(x&&y == 0)
    {
        cout<<x<<" "<<y<<endl;
        return;
    }
    ans(x,y);
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