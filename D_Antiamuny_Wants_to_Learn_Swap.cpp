#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> ST;
    int n;

public:
    SegmentTree(vector<int> &arr)
    {
        n = arr.size();
        ST.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(vector<int> &arr, int curr, int l, int r)
    {
        if (l == r)
        {
            ST[curr] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * curr + 1, l, mid);
        build(arr, 2 * curr + 2, mid + 1, r);
        ST[curr] = max(ST[2 * curr + 1], ST[2 * curr + 2]);
    }

    int RMQ(int qs, int qe, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (qs > r || qe < l)
            return 0; 
        if (qs <= l && qe >= r)
            return ST[curr];
        int mid = (l + r) / 2;
        int p1 = RMQ(qs, qe, 2 * curr + 1, l, mid);
        int p2 = RMQ(qs, qe, 2 * curr + 2, mid + 1, r);
        return max(p1, p2);
    }

    void update(int idx, int val, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            ST[curr] = max(ST[curr], val);
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * curr + 1, l, mid);
        else
            update(idx, val, 2 * curr + 2, mid + 1, r);
        ST[curr] = max(ST[2 * curr + 1], ST[2 * curr + 2]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> P(n + 1, 0);
    vector<int> init_p(n + 1, 0);
    SegmentTree st_p(init_p);

    for (int j = 1; j <= n; j++)
    {
        int val = a[j];
        int res = st_p.RMQ(val + 1, n);
        if (res != 0)
            P[j] = res;
        st_p.update(val, j);
    }

    vector<int> M(n + 1, 0);
    vector<int> init_m(n + 1, 0);
    SegmentTree st_m(init_m);

    for (int k = 1; k <= n; k++)
    {
        int val = a[k];
        int res = st_m.RMQ(val + 1, n);
        if (res != 0)
            M[k] = res;
        if (P[k] != 0)
            st_m.update(a[k], P[k]);
    }

    SegmentTree st_final(M);

    for (int qq = 0; qq < q; qq++)
    {
        int l, r;
        cin >> l >> r;
        int max_M = st_final.RMQ(l, r);
        if (max_M >= l)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
