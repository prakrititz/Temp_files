#include <bits/stdc++.h>
using namespace std;

long long count_inversion(vector<long long> &a, long long left, long long right)
{
    if (left >= right)
        return 0;
    long long mid = (left + right) / 2;
    long long inv_count = count_inversion(a, left, mid) + count_inversion(a, mid + 1, right);

    vector<long long> temp;
    long long i = left, j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (a[i] < a[j])
        {
            temp.push_back(a[i++]);
        }
        else
        {
            temp.push_back(a[j++]);
            inv_count += (mid - i + 1);
        }
    }
    while (i <= mid)
        temp.push_back(a[i++]);
    while (j <= right)
        temp.push_back(a[j++]);

    for (long long k = 0; k < temp.size(); k++)
        a[left + k] = temp[k];

    return inv_count;
}

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    cout << count_inversion(a, 0, n - 1) << "\n";
}

long long main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}