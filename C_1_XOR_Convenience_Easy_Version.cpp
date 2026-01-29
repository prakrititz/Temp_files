#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    p[n] = 1;
    vector<bool> used(n + 1, false);
    used[1] = true;
    for (int i = 2; i < n; ++i) {
        p[i] = i ^ 1;  // This does +1 for evens, -1 for odds
        used[p[i]] = true;
    }
    for (int v = 1; v <= n; ++v) {
        if (!used[v]) {
            p[1] = v;
            break;
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << p[i] <<" ";
    }
    cout << endl;
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