#include <bits/stdc++.h>
using namespace std;

long long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right)
{
    long long inversions = 0;
    int i = left;
    int j = mid;
    int k = left;
    while (i <= mid - 1 && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inversions += (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inversions;
}

long long mgSrt(vector<int> &arr, int left, int right, vector<int> &temp)
{
    long long inversions = 0;
    if (left < right)
    {
        int mid = (left + right) / 2;
        inversions += mgSrt(arr, left, mid, temp);
        inversions += mgSrt(arr, mid + 1, right, temp);
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}

long long cntInv(vector<int> &arr, int n)
{
    vector<int> temp(n);
    return mgSrt(arr, 0, n - 1, temp);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < n; j++)
        cin >> b[j];

    vector<int> a_copy = a;
    vector<int> b_copy = b;

    long long ina = cntInv(a, n);
    long long inb = cntInv(b, n);

    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            flag = false;
            break;
        }
    }

    if (ina % 2 == inb % 2 && flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
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