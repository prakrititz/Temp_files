#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9 + 7;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, vector<int>& a) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INF;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        return min(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int get_min(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    SegmentTree st(a);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i, x;
            cin >> i >> x;
            st.update(i - 1, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--; r--;

            int low = 0, high = r - l;
            int ans = -1;

            while (low <= high) {
                int mid = (low + high) / 2;
                if (st.get_min(l, l + mid) <= mid) {
                    ans = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (ans != -1 && st.get_min(l, l + ans) == ans)
                cout << 1 <<endl;
            else
                cout << 0 <<endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;
    while (tc--) solve();
    return 0;
}
