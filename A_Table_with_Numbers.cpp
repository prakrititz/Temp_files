#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n, h, l;
    cin>>n>>h>>l;
    vector<int>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    sort(a.begin(), a.end());
    int cnt1 = 0;
    int cnt2 = 0; 
    int cnt3 = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i]<=l && a[i]<=h)cnt3++;
        else if(a[i]<=l)cnt1++;
        else if(a[i]<=h)cnt2++;
    }
    int total = cnt1 + cnt2 + cnt3;
    cout<<min(cnt3, total / 2)<<endl;
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