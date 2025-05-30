#include <bits/stdc++.h>
using namespace std;
long long merge(vector<long long> &arr, vector<long long> &temp, long long left, long long mid, long long right)
{
    long long inversions = 0;
    long long i = left;
    long long j = mid;
    long long k = left;
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

long long mgSrt(vector<long long> &arr, long long left, long long right, vector<long long> &temp)
{
    long long inversions = 0;
    if (left < right)
    {
        long long mid = (left + right) / 2;
        inversions += mgSrt(arr, left, mid, temp);
        inversions += mgSrt(arr, mid + 1, right, temp);
        inversions += merge(arr, temp, left, mid + 1, right);
    }
    return inversions;
}

long long cntInv(vector<long long> &array)
{
    long long n = array.size();
    vector<long long> temp(n);
    return mgSrt(array, 0, n - 1, temp);
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    if (n < 4)
    {
        for (long long i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    if (n == 4)
    {
        vector<long long> temp = a;
        swap(temp[0], temp[2]), swap(temp[1], temp[3]);
        long long an = a[0] * 1e3 + a[1] * 1e2 + a[2] * 1e1 + a[3];
        long long tn = temp[0] * 1e3 + temp[1] * 1e2 + temp[2] * 1e1 + temp[3];
        if (an < tn)
        {
            for (long long i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << endl;
            return;
        }
        else
        {
            for (long long i = 0; i < n; i++)
                cout << temp[i] << " ";
            cout << endl;
            return;
        }
    }
    vector<long long> o;
    vector<long long> e;
    set<long long> od;
    set<long long> ev;
    for (long long i = 0; i < n; i++)
    {
        if (i % 2)
        {
            od.insert(a[i]);
            o.push_back(a[i]);
        }
        else
        {
            ev.insert(a[i]);
            e.push_back(a[i]);
        }
    }
    vector<long long> ans(n);
    bool flag = false;
    long long ino = cntInv(o);
    long long ine = cntInv(e);
    // cout << ino << " " << ine << endl;
    if (ino % 2 != ine % 2)
        flag = true;
    for (long long i = 0; i < n; i++)
    {
        if (i % 2)
        {
            ans[i] = *od.begin();
            od.erase(od.begin());
        }
        else
        {
            ans[i] = *ev.begin();
            ev.erase(ev.begin());
        }
    }
    if (flag)
        swap(ans[n - 1], ans[n - 3]);
    for (long long i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
}

int main()
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