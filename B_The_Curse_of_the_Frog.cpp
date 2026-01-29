#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    int x;
    cin >> n >> x;
    int total = 0;
    int maxi= LONG_LONG_MIN;
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        total += a * (b - 1);
        int current_cycle_gain = a * b - c;
        if (current_cycle_gain > maxi) {
            maxi= current_cycle_gain;
        }
    }
    if (total >= x) {
        cout << 0 <<endl;
        return;
    }
    if (maxi<= 0) {
        cout << -1 <<endl;
        return;
    }
    int rollbacks = (x - total + maxi- 1) / maxi;
    cout << rollbacks <<endl;
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