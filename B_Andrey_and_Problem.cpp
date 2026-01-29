#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{
    int n;   
    cin>>n;
    vector<double>a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    double b = 1;
    double maxi = 0;
    sort(a.rbegin(), a.rend());
    for(int i = 0;i<n ;i ++)
    {       
        double p = b*a[i] + maxi*(1-a[i]);
        if(p>maxi)
        {
            maxi = p;
            b*=(1-a[i]);
        }
        else break;
    }
    cout<<fixed<<setprecision(12)<<maxi<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}