#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool sorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) sorted = false;
    }

    if (sorted) {
        cout << "Bob" << endl;
        return;
    }

    cout << "Alice" << endl;
    int zeros = 0;
    for (char c : s) if (c == '0') zeros++;

    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i < zeros && s[i] == '1') ans.push_back(i + 1);
        else if (i >= zeros && s[i] == '0') ans.push_back(i + 1);
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
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