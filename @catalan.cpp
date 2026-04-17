#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 1e9+7;
vector<int>c(1e6);
int power(int x, int n){
    int res = 1;
    while(n){
        if(n%2){
            res = (res*x)%mod;
        } 
        x = (x*x)%mod;
        n = n/2;
    }
    return res;
}
void Catalan(){
    c[0] = 1;
    c[1] = 1;
    for(int i = 2;i<c.size();i++)
    {
        c[i] = 0;
        for(int j = 0;j<i;j++)
        {
            c[i] = (c[i] + (c[i-j-1]*c[j])%mod)%mod;
        }
    }
}
void catalan2()
{
    c[0] =1 ;
    c[1] = 1;
    for(int i = 2;i<c.size();i+=1)
    {
        c[i] = (((2*(2*i-1)%mod)*c[i-1])%mod*(power(i+1,mod-2)))%mod;
    }
}
void solve()
{
    int n;
    cin>>n;
    if(n==0)
    {
        cout<<0<<endl;
        return;
    }
    if(n%2)
    {
        cout<<0<<endl;
        return;
    }
    cout<<c[n/2]<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    // Catalan();
    catalan2();
    while(tc--)
    {
        solve();
    }
    return 0;
}