#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n+5, vector<int>(n+5));
    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <=n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> temp;
    for(int i = 1; i <= n; i++) {
        int count = 0;
        for(int j = n; j >= 1 && a[i][j] == 1; j--) {
            count++;
        }
        temp.push_back(count);
    }
    sort(temp.begin(), temp.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (temp[i]>=ans) {
            ans++;
        }
    }
    cout << ans << endl;
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