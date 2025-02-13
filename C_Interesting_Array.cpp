#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n,m;
    cin>>n>>m;
    vector<long long>a(n+1);
    map<long long, long long>freq;
    vector<long long>prev(n+1, 0);
    for(long long i = 1; i<=n;i++)
    {
        cin>>a[i];
    }
    long long count = 0;
    for(long long j = 1; j<=m; j++)
    {
        long long i, val;
        cin>>i>>val;
        if(a[i]!=val)
        {
            freq[a[i]] += j-prev[i];
            a[i] = val;
            prev[i] = j;
        }
    }
    for(long long i = 1; i<=n ; i++)
    {
        freq[a[i]]+=(m+1-prev[i]);
    }
    for(auto p:freq)
    {
        count -= (p.second*(p.second-1))/2;   
    }
    count += m*(m+1)*n;
    cout<<count<<endl;
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