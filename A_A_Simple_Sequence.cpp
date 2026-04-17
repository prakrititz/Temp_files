#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n;i++)a[i] = i+1;
    reverse(a.begin(), a.end());
    for(auto it:a)cout<<it<<" ";
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