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
    vector<long long> mp(n, 0);
    for (long long i = 1; i < n - 1; i++)
    {
    
        if (a[i] <=a[i + 1])
        {
            mp[i] += a[i + 1] + 1 - a[i];
        }
        if (a[i] <= a[i - 1])
        {
            mp[i] = max(a[i - 1] + 1 - a[i], mp[i]);
        }
        // cout<<mp[i]<<" ";
    }
    // cout<<endl;
    vector<long long> odd(n);
    vector<long long> even(n);
    long long deff = 0;
    for (long long i = 1; i < n - 1; i += 2)
    {
        // cout<<mp[i]<<" ";
        deff += mp[i];
        odd[i] = deff;
    }
    // cout<<endl;
    if ((n - 2) % 2 != 0)
    {
        cout << deff << endl;
    }
    else
    {
        // cout<<deff<<endl;
        long long cheff = 0;
        for (long long i = n-2; i >= 2; i -= 2)
        {
            // cout<<mp[i]<<" ";
            cheff += mp[i];
            even[i]= cheff;
        }
        // cout<<endl;
        long long ans = min(cheff, deff);
        for(long long i = 1; i<=n-5; i+=2)
        {
            ans = min(ans, odd[i]+even[i+3]);
        }
        cout<<ans<<endl;
    }
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