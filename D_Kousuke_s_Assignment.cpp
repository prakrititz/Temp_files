#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n;cin>>n;
    vector<long long>a(n+1);
    map<long long, long long>mp;mp[0]++;
    for(long long i = 1;i<n+1;i++)cin>>a[i];
    long long curr_end = 0;
    long long curr_sum = 0;
    long long count = 0;
    for(long long i = 1;i<=n ; i++)
    {
        curr_sum+=a[i];
        if(mp[curr_sum]==0)
        {
            mp[curr_sum]++;continue;
        }
        count++;
        curr_sum = 0;
        mp.clear();
        mp[0]++;
    }
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