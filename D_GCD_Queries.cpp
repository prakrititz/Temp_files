#include<bits/stdc++.h>
using namespace std;
#define int long long 
int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << "! 1 2" << endl;
        int res;
        cin >> res;
        return;
    }
    int c1 = 1;
    int c2 = 2;

    for (int c3 = 3; c3 <= n; ++c3) {
        int g1 = ask(c1, c2);
        int g2 = ask(c2, c3);
        if (g1 == g2) {
            c2 = c3; 
        } else if (g1 > g2) {
        } else {
            c1 = c2;
            c2 = c3;
        }
    }
    cout << "! " << c1 << " " << c2 << endl;
    int res;
    cin >> res;
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