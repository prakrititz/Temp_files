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
        ST[curr] = gcd(ST[2 * curr + 1], ST[2 * curr + 2]);
    }

    int RGCD(int qs, int qe, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (qs > r || qe < l)
            return 0;
        if (qs <= l && qe >= r)
            return ST[curr];
        int mid = (l + r) / 2;
        return gcd(RGCD(qs, qe, 2 * curr + 1, l, mid),
                   RGCD(qs, qe, 2 * curr + 2, mid + 1, r));
    }

    void update(int idx, int val, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            ST[curr] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * curr + 1, l, mid);
        else
            update(idx, val, 2 * curr + 2, mid + 1, r);
        ST[curr] = gcd(ST[2 * curr + 1], ST[2 * curr + 2]);
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b;
    for (int i = 1; i < n; i++)
        b.push_back(abs(a[i - 1] - a[i]));
    if (n == 1)
        b.push_back(a[0]);
    SegmentTree ST(b);
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r)
        {
            cout << 0 << " ";
        }
        else
        {
            cout << ST.RGCD(l, r - 1) << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}