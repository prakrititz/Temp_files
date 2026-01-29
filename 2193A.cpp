#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n, s, x;
    cin>>n>>s>>x;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    int sum = accumulate(a.begin(), a.end(), 0LL);
    if(s<sum)cout<<"NO"<<endl;
    else{
        if((s-sum)%x==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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