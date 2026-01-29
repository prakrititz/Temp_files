#include<bits/stdc++.h>
using namespace std;
#define int long long 
int MOD = 1e9 + 7;
void solve() {
    int n;
    int c;
    cin >> n >> c;
    string s;
    cin >> s;
    if (s[n-1] == '0' || s[0]=='0') {
        cout << "-1"<<endl;
        return;
    }
    int ans = 1;  
    int exp = 0;
    int f = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '1') {
            ans = (ans * 2) % MOD;
            f = (f * 2) % c;
        } else {
            ans = (ans * exp) % MOD;
            f = (f * exp) % c;
        }
        exp++;
    }
    if (f==0) {
        cout << "-1"<<endl;
    } else {
        cout << ans <<endl;
    }
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