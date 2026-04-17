#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    for(int i = 0;i<n;i++)cin>>b[i];
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        if(i==0)
        {
            int largest_gcd = gcd(a[0], a[1]);
            if(largest_gcd<a[0])
            {
                ans++;
            }
        }
        else if(i==n-1)
        {
            int largest_gcd = gcd(a[n-1], a[n-2]);
            if(largest_gcd<a[n-1])
            {
                ans++;
            }
        }
        else{
            int largest_gcd = lcm(gcd(a[i], a[i+1]) , gcd(a[i], a[i-1]));
            if(largest_gcd<a[i])
            {
                ans++;
            }
        }
    }
    cout<<ans<<endl;
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