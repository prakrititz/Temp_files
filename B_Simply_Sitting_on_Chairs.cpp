#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> m(n, 0);
    for(int i = 0;i<n;i++)
    {
        m[a[i]-1] = i; 
    }
    int len = 0, ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(m[i]>=i)
        {
            len++;
        }
        ans = max(ans, len);
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc = 1;
    cin >> tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}