#include <bits/stdc++.h>
using namespace std;

void solve() {
        long long int n, x, y;
        cin>>n>>x>>y;
        long long int ans = 0;
        long long int X = n/x;
        long long int Y = n/y;
        long long int XY = n/lcm(x,y);
        X-=XY;
        Y-=XY;
        ans += ((X)*(2*n- (X-1)))/2;
        ans-= ((Y)*(2*1 + (Y-1)))/2;
        cout<<ans<<endl;
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