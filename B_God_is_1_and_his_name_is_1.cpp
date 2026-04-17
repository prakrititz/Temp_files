#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int MAXN = 200000;
vector<int> spf(MAXN + 1);
void seive(){
    for(int i = 1;i<=MAXN;i++)spf[i]= i;
    for(int i = 2;i*i<=MAXN;i++)
    {
        if(spf[i]==i)
        {
            for(int j = i*i;j<=MAXN;j+=i){
                if(spf[j]==j)spf[j] = i;
            }
        }
    }
}

int sumP(int x)
{
    int sum = 0;
    while(x>1)
    {
        sum += spf[x];
        x/= spf[x];
    }
    return sum;
}
void solve()
{
    int n;
    cin>>n;
    if(n==1)cout<<0<<endl;
    else if(n==2)cout<<1<<endl;
    else{
        cout<<min(sumP(n), sumP(n-1))<<endl;
    }   
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    seive();
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}