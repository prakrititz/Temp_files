#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k;
    cin>>n>>k;
    map<int, int>mp;
    vector<int>a(n);
    for(int i =0 ;i< n ;i++)
    {
        cin>>a[i];
        mp[a[i]]++;
    }
    int count = 0;
    for(int i = 0 ;i<n ;i++)
    {
        int diff = k-a[i];
        if(mp[diff]>0)
        {
            count++;
            mp[diff]--;
        }
    }
    cout<<count/2<<endl;
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