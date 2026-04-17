#include<bits/stdc++.h>
using namespace std;
#define int long long 
int m = 998224353;
int maxn = 1e6;
vector<int>fact(maxn+4);
vector<int>invFact(maxn+4);
vector<int> prefix(maxn+4);
vector<int> D(maxn+4);
int power(int x, int n){
    int res = 1;
    while(n){
        if(n%2){
            res = (res*x)%m;
        } 
        x = (x*x)%m;
        n = n/2;
    }
    return res;
}
int add(int a, int b){
   return ((a % m) + (b % m)) % m;
}
int mul(int a, int b){
   return ((a % m) * (b % m)) % m;
}
void findDerangement() {
    D[0] = 0;
    D[1] = 0;
    D[2] = 1;
    for (int i = 3; i <= maxn; i++) {
        D[i] = mul(i - 1, add(D[i - 2], D[i - 1]));
    }
}
void precompute()
{
    fact[0] = 1;
    fact[1] = 1;
    for(int i= 2;i<=maxn;i++)
    {
        fact[i] = (fact[i-1]*i)%m;
    }
    invFact[0] = 1;
    invFact[1] = 1;
    for(int i = 2;i<=maxn;i++)
    {
        invFact[i] = power(fact[i], m-2);
    }
    prefix[0] = 0, prefix[1] = 0;
    for(int i = 2; i<=maxn; i++){
        if(i%2) prefix[i] = (prefix[i-1] + invFact[i])%m;
        else prefix[i] = (prefix[i-1] - invFact[i]+m)%m;
    }
}
void solve()
{ 
    int n;
    cin>>n;
    int ans = 1;
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    else{
       int ans = ((n*(n-1))/2)%m;
       int x = (D[n]-D[n-2]+m)%m;
       ans = (ans*x)%m;
       cout<<ans<<endl;
    }
}   
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    precompute();
    findDerangement();
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}