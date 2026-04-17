#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<int>f(n);
    for(int i = 0;i<n;i++)cin>>f[i];
    vector<int>a(n);
    int sum = 0;
    for(int i = 2;i<=n-1;i++)
    {
        a[i-1] = -1*(2*f[i-1]-f[i-2]-f[i])/2;
        sum += (i-2)*a[i-1];
    }
    int S = (f[0] + f[n-1]) / (n-1);
    a[0] = (f[1] - f[0] + S) / 2;
    int S2 = 0;
    for(int i = 0; i < n-1; i++)
        S2 += a[i];
    a[n-1] = S - S2;
    for(auto it: a)cout<<it<<" ";
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