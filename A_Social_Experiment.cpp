#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    if(n==2){
        cout<<2<<endl;
    }   
    else if(n==3)
    {
        cout<<3<<endl;
    }
    else if(n%2==0){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
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