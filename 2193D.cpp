#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0;i<n ;i++)cin>>a[i];
    sort(a.begin(), a.end());
    for(int i = 0;i<n;i++)cin>>b[i];
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + b[i - 1];
    }
    int ans = LONG_LONG_MIN;
    for (int k = 1; k <= n; k++) {
        if (pref[k] > n) break;
        int idx = n - pref[k];
        int x = a[idx];

        ans = max(ans, x * k);
    }

    cout << ans <<endl;
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