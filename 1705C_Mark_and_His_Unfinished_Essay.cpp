#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    
    string s;
    cin >> s;
    
    vector<long long> pref(c + 1);
    vector<pair<long long, long long>> v(c);
    pref[0] = n;
    
    for(int i = 0; i < c; i++) {
        cin >> v[i].first >> v[i].second;
        v[i].first--;
        v[i].second--;
        pref[i + 1] = pref[i] + (v[i].second - v[i].first + 1);
    }
    while(q--) {
        long long k;
        cin >> k;
        k--; 
        for(int i = c - 1; i >= 0; i--) {
            if(k >= pref[i]) {
                long long diff = k - pref[i];
                k = v[i].first + diff;
            }
        }
        
        cout << s[k] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
    
    return 0;
}