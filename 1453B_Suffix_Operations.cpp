#include <bits/stdc++.h>
using namespace std;

void solve() {

    long long int n;
    cin>>n;
    vector<long long int>a(n);
    for (long long int i = 0; i < n; i++) {
        cin>>a[i];
    }
    long long int ans = 0;
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    for (long long int i = 1; i < n; i++) {
        ans += abs(a[i]-a[i-1]);
    }
    long long int maxi = 0;
    maxi = max(abs(a[0]-a[1]), abs(a[n-1]-a[n-2]));
    for(long long int i= 1; i< n-1; i++)
    {
        maxi = max(maxi, abs(a[i]-a[i-1]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]));
    }
    ans -= maxi;
    cout<<ans<<endl;
}

 int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}