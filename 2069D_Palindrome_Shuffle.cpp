#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    bool is_pal = true;
    for(int i = 0; i < n/2; i++) {
        if(s[i] != s[n-1-i]) {
            is_pal = false;
            break;
        }
    }
    if(is_pal) {
        cout << 0 << endl;
        return;
    }
    
    for(int len = 1; len <= n; len++) {
        for(int start = 0; start + len <= n; start++) {
            int end = start + len - 1;
            
            string prefix = s.substr(0, start);
            string suffix = s.substr(end + 1);
            string middle = s.substr(start, len);
            
            sort(middle.begin(), middle.end());
            bool found = false;
            do {
                string candidate = prefix + middle + suffix;
                bool is_palindrome = true;
                
                for(int i = 0; i < candidate.length()/2; i++) {
                    if(candidate[i] != candidate[candidate.length()-1-i]) {
                        is_palindrome = false;
                        break;
                    }
                }
                
                if(is_palindrome) {
                    found = true;
                    break;
                }
            } while(next_permutation(middle.begin(), middle.end()));
            
            if(found) {
                cout << len << endl;
                return;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}