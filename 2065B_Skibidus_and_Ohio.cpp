#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int c=0;
    if(s.size() == 1) cout << 1 << endl;
    else{
        for(int i=s.size();i>0;i--){
            if(s[i] == s[i-1]) {
                cout<<1<<endl;
                return ;
            }
        }
    }
    cout << s.size() << endl;
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