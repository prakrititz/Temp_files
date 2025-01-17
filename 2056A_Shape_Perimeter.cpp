#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>>a;
    int perimeter = n*4*m;
    for(int i = 0;i< n ;i++)
    {
        int x, y;
        cin>>x>>y;
        a.push_back({x, y});
    }
    for(int i = 1;i<n;i++)
    {
        perimeter -= 2*(m-a[i].first+m-a[i].second);
    }
    cout<<perimeter<<endl;

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