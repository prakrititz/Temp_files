#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = LONG_LONG_MIN;
    for(long long i = n-1 ; i>1;i --)
    {
        ans = max(ans, abs(a[0]-a[i])+abs(a[i]-a[i-1]));
    }
    for(long long i = 0 ; i<=n-3;i++)
    {
        ans = max(ans, abs(a[n-1]-a[i])+abs(a[i]-a[i+1]));
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}