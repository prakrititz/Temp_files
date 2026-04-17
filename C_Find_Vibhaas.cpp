#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int lx = 0; int hx = 1e9;
    int ly = 0; int hy= 1e9;
    while(lx<=hx || ly<=hy)
    {
        int mx = (lx+hx)/2;
        int my = (ly+hy)/2;
        cout<<"? "<<mx<<" "<<my<<endl;
        string s;
        cin>>s;
        if(s=="HERE"){
            cout<<"! "<<mx<<" "<<my<<endl;
            return;
        }
        else if(s=="LEFT")
        {
            hx = mx-1;
            ly = hy = my;
        }
        else if(s=="RIGHT"){
            lx= mx+1;
            ly = hy = my;
        }
        else if(s=="DOWN")
        {
            hy = my-1;
            lx = hx = mx;
        }
        else if(s=="UP")
        {
            ly = my+1;
            lx = hx = mx;
        }
        else if(s=="LEFT_DOWN")
        {
            hx = mx-1;
            hy = my-1;
        }
        else if(s=="RIGHT_DOWN")
        {
            lx= mx+1;
            hy = my-1;
        }
        else if(s=="LEFT_UP")
        {
            hx = mx-1;
            ly = my+1;
        }
        else if(s=="RIGHT_UP")
        {
            lx= mx+1;
            ly = my+1;
        }
    }   
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