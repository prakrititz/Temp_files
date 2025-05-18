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

void solve()
{
    vector<int> s = {0, 0, 0, 0, 1}; // Input array of size 5
    SegmentTree ST(s);

    // Print initial segment tree
    // cout << "Initial segment tree: ";
    // for (int i = 0; i < arr.size(); i++)
    //     cout << arr[i] << " ";
    // cout << endl;

    // // Compute size for update and RSQ
    // int n = s.size();
    // int size = pow(2, ceil(log2(n))); // size = 8 for n = 5

    // Update index 2 with value 1
    ST.update(2, 1);
    // Range sum query for [1, 3]
    int R = ST.RSQ(1, 3);
    cout << "Sum of range [2, 4]: " << R << endl;
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