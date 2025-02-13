#include <bits/stdc++.h>
using namespace std;

void solve() {
    int X, Y, K;
    cin>>X>>Y>>K;
    int s = min(X, Y);
    cout<<0<<" "<<0<<" "<<s<<" "<<s<<endl;
    cout<<s<<" "<<0<<" "<<0<<" "<<s<<endl;
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