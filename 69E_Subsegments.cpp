#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, K;
    cin >> n >> K;
    
    vector<int> a(n);
    map<int, int> mp;
    set<int> s;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < K - 1; i++) {
        mp[a[i]]++;
        if (mp[a[i]] == 1) s.insert(a[i]);
        if (mp[a[i]] == 2) s.erase(a[i]);
    }

    for (int i = K - 1; i < n; i++) {
        mp[a[i]]++;
        if (mp[a[i]] == 1) s.insert(a[i]);
        if (mp[a[i]] == 2) s.erase(a[i]);

        if (s.empty()) {
            cout << "Nothing\n";
        } else {
            cout << *s.rbegin() << "\n";
        }

        mp[a[i - K + 1]]--;
        if (mp[a[i - K + 1]] == 1) s.insert(a[i - K + 1]);
        if (mp[a[i - K + 1]] == 0) s.erase(a[i - K + 1]);
    }

    return 0;
}
