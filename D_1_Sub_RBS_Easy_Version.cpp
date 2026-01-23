#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{  int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> mp(n + 1,0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '(') mp[i]++;
        else mp[i] = mp[i + 1];
    }
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == ')' && s[i + 1] == '(') {
            if (mp[i + 2]) {
                cout << n - 2 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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