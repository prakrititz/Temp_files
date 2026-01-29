#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n, q;
    cin>>n>>q;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0;i<n ;i ++)cin>>a[i];
    for(int i = 0;i<n ;i++)cin>>b[i];
    a[n-1] = max(a[n-1], b[n-1]);
    for(int i = n-2;i>=0;i--)
    {
        a[i] = max(a[i],max(a[i+1], b[i]));
    }
    vector<int>pre(n+1, 0);
    for(int i = 1;i<=n;i++)
    {
        pre[i] = pre[i-1]+a[i-1];
    }   
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<pre[r]-pre[l-1]<<" ";
    }
    cout<<endl;
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