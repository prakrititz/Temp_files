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
        ST[curr] = ST[2 * curr + 1] + ST[2 * curr + 2];
    }
    int RSQ(int qs, int qe, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (qs > r || qe < l)
            return 0;
        if (qs <= l && qe >= r)
            return ST[curr];
        int mid = (l + r) / 2;
        return RSQ(qs, qe, 2 * curr + 1, l, mid) + RSQ(qs, qe, 2 * curr + 2, mid + 1, r);
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
        ST[curr] = ST[2 * curr + 1] + ST[2 * curr + 2];
    }
};
bool check(int pos, int n, vector<pair<int, int>> seg, vector<int> qes)
{
    vector<int> arr(n, 0);
    bool flag = false;
    SegmentTree ST(arr);
    for (int i = 0; i < pos; i++)
    {
        int x = qes[i];
        x--;
        ST.update(x, 1);
    }
    for (int j = 0; j < seg.size(); j++)
    {
        int l = seg[j].first;
        int r = seg[j].second;
        int len = r - l + 1;
        int sum = ST.RSQ(l - 1, r - 1);
        if (sum > len - sum)
        {
            flag = true;
            break;
        }
    }

    return flag;
}
void solve()
{
    int m, n;
    cin >> n >> m;
    vector<int> arr(n, 0);
    vector<pair<int, int>> seg;
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        seg.push_back({l, r});
    }

    int q;
    cin >> q;
    int ans = -1;
    vector<int> qes(q);
    for (int i = 0; i < q; i++)
        cin >> qes[i];
    int lo = 0, hi = q;
    if (!check(q, n, seg, qes))
    {
        cout << -1 << endl;
        return;
    }
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, n, seg, qes))
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << lo << endl;
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