#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<pair<int, int>>a(n);
    for(int i = 0;i < n;i++)
    {
        cin>>a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin>>a[i].second;
    }
    sort(a.rbegin(), a.rend());
    int count = 0; int walk = 0;
    for(int i =0 ;i<n ;i++)
    {
        if(walk+a[i].second>a[i].first)
        {
            count = a[i].first;
            break;

        }
        walk+=a[i].second;
    }
    cout<<max(walk , count)<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}