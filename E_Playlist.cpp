#include<bits/stdc++.h>
using namespace std;
#define int long long 
bool comparator(pair<long double, long double >&p1, pair<long double, long double >&p2)
{
    return p1.first*p1.second*(1-p2.second) < p2.first*p2.second*(1-p1.second);
}
void solve()
{   
    int n;
    cin>>n;
    vector<pair<long double, long double >>p;
    for (int i = 0;i<n;i++)
    {
        long double x;long double y;
        cin>>x>>y;
        y/=100;
        long double v = (x*y)/(1-y);
        p.push_back({x,y});
    }
    sort(p.rbegin(), p.rend(), comparator);
    long double ans = 0;
    long double p1 = 0;
    for(int i = n-1;i>=0;i--)
    {
        ans += p[i].first + p1*p[i].second*p[i].first;
        p1 += (1-p[i].second);
    }
    cout<<fixed<<setprecision(9)<<ans<<endl;
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
