#include <bits/stdc++.h>
using namespace std;

const long long     mod =  998244353;
void solve() {
    long long n, m;
    cin>>n>>m;
    vector<long long>a(n);
    for(long long i = 0;i<n;i++)cin>>a[i];
    vector<pair<long long, pair<long long, long long>>>edges;
    vector<map<long long,vector<long long>>>adj(n);
    map<pair<long long, long long>, long long>mp;
    for(long long i = 0;i<m;i++)
    {
        long long x, y;
        cin>>x>>y;
        x--, y--;
        adj[x][a[y]].push_back(y);
        edges.push_back({(a[x]+a[y]), {x, y}});
        mp[{x,y}] = 1;
    }
    sort(edges.begin(), edges.end());
    map<long long, vector<pair<long long, long long>>>g;
    for(auto it: edges)
    {
        long long sum = it.first;
        g[sum].push_back({it.second.first, it.second.second});
    }
    for(auto it: g)
    {
        map<long long, long long>total;
        long long sum = it.first;
        for(auto p: it.second)
        {
            long long u = p.first;
            long long v = p.second;
            total[v] =  (total[v] + mp[{u,v}])%mod;
        }
        for(auto it: total)
        {
            long long v = it.first;
            long long val = it.second;
            for(auto x: adj[v][sum])
            {
                mp[{v,x}] = (mp[{v,x}]+val)%mod;
            }
        }
    }
    long long ans = 0;
    for(auto it: edges)
    {
        ans = (ans+ mp[{it.second.first, it.second.second}])%mod;
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}