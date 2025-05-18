#include <bits/stdc++.h>
using namespace std;
class MaxSeg
{
    vector<int> ST;
    int n;

public:
    MaxSeg(vector<int> &arr)
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
    int RSQ(int qs, int qe, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (qs > r || qe < l)
            return INT_MIN;
        if (qs <= l && qe >= r)
            return ST[curr];
        int mid = (l + r) / 2;
        return max(RSQ(qs, qe, 2 * curr + 1, l, mid), RSQ(qs, qe, 2 * curr + 2, mid + 1, r));
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
        ST[curr] = max(ST[2 * curr + 1], ST[2 * curr + 2]);
    }
};
class MinSeg
{
    vector<int> ST;
    int n;

public:
    MinSeg(vector<int> &arr)
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
        ST[curr] = min(ST[2 * curr + 1], ST[2 * curr + 2]);
    }
    int RSQ(int qs, int qe, int curr = 0, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (qs > r || qe < l)
            return INT_MAX;
        if (qs <= l && qe >= r)
            return ST[curr];
        int mid = (l + r) / 2;
        return min(RSQ(qs, qe, 2 * curr + 1, l, mid), RSQ(qs, qe, 2 * curr + 2, mid + 1, r));
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
        ST[curr] = min(ST[2 * curr + 1], ST[2 * curr + 2]);
    }
};
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    vector<int> left(n);
    vector<int> right(n);
    MaxSeg Mx(a);
    MinSeg Mn(b);
    map<int, int> mp1;
    for (int i = 0; i < n; i++)
    {
        mp1[a[i]] = i;
        if (mp1.find(b[i]) == mp1.end())
            left[i] = -1;
        else
            left[i] = mp1[b[i]];
    }
    mp1.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        mp1[a[i]] = i;
        if (mp1.find(b[i]) == mp1.end())
            right[i] = -1;
        else
            right[i] = mp1[b[i]];
    }
    for (int i = 0; i < n; i++)
    {
        if (left[i] != -1 && Mx.RSQ(left[i], i) <= b[i] && Mn.RSQ(left[i], i) >= b[i])
            continue;
        if (right[i] != -1 && Mx.RSQ(i, right[i]) <= b[i] && Mn.RSQ(i, right[i]) >= b[i])
            continue;
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
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