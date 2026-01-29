#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n==1)
    {
        cout<<1<<endl;return;
    }
    int ans = 0;
    for (char c : s) {
        if (c == '1') ans++;
    }
    s = "10" + s + "01";
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            cnt++;
        } else {
            ans += cnt / 3;
            cnt = 0;
        }
    }
    
    cout << ans << endl;
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