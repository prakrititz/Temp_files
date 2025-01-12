#include <bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, d, k;
        cin >> n >> d >> k;
        vector<pair<int, int>> segs;
        for (int i = 0; i < k; i++) {
            int l, r;
            cin >> l >> r;
            segs.push_back(make_pair(l, r));
        }
        int mx = 0, mn = INT_MAX, b = -1, m = -1;
        sort(segs.begin(), segs.end());
        priority_queue<int, vector<int>, greater<int>>  q;
        int i = 1;
        int j = 0;
        while (i <= n - d + 1) {
            while (j < segs.size() && segs[j].first <= i + d - 1) {
                q.push(segs[j].second);
                j++;
            }
            while (!q.empty() && q.top() < i) {
                q.pop();
            }
            int c = q.size();
            if (c > mx) {
                mx = c;
                b = i;
            }
            if (c < mn) {
                mn = c;
                m = i;
            }
            i++;
        }
            cout << b << ' ' << m << '\n';
    }
    return 0;
}
