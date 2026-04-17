#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    map<int, int>mp;
    for(int i =0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
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