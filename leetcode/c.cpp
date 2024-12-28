#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tc;
    cin >> tc;
    while(tc--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> missing(m);
        for(int i = 0; i < m; i++) {
            cin >> missing[i];
        }
        
        set<int> known;
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            known.insert(x);
        }
        
        string result;
        if(k == n) {
            result = string(m, '1');
        }
        else if(k <= n-2) {
            result = string(m, '0');
        }
        else {
            for(int i = 0; i < m; i++) {
                result += (known.count(missing[i]) == 0) ? '1' : '0';
            }
        }
        
        cout << result << "\n";
    }
    return 0;
}
