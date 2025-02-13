#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n =0;
    string s;
    cin>>s;
    for(int i = 0;i < s.size(); i++)if(s[i]=='1')n++;
    cout<<n<<endl;
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