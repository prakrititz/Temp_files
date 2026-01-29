#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n ;i ++)cin>>a[i]; 
    sort(a.begin(), a.end());
    int mx = a.back();
    vector<int>dp(n+1, INT_MAX);
    for(auto it: a)dp[it] = 1;
    for (int x = 1; x <= n; x++)
    {
        if (dp[x] == INT_MAX) continue;
        for (int m = x; m <= n; m += x)
        {
            int k = m / x;
            if (dp[k] != INT_MAX)
            {
                dp[m] = min(dp[m], dp[k] + dp[x]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == INT_MAX) cout << -1 << " ";
        else cout << dp[i] << " ";
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