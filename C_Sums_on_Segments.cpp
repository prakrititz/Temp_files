#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(vector<long long> &arr)
{
    if (!arr.size())
    {
        return 0;
    }
    long long res = arr[0];
    long long maxEnding = arr[0];
    for (long long i = 1; i < arr.size(); i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i] * 1ll);
        res = max(res, maxEnding);
    }
    return max(res, 0ll);
}
void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    bool flag = true;
    long long ind = -1;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        if (abs(a[i]) != 1)
        {
            flag = false;
            ind = i;
        }
    }
    if (flag)
    {
        vector<long long> ans;
        vector<long long> t2;
        for (long long i = 0; i < n; i++)
        {
            t2.push_back(-a[i]);
        }
        long long r = maxSubarraySum(a);
        long long l = -maxSubarraySum(t2);
        for (long long i = l; i <= r; i++)
        {
            ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (long long i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    else
    {
        vector<long long> v1;
        vector<long long> t1;
        vector<long long> v2;
        vector<long long> t2;
        long long sum = 0;
        set<long long> s1, s2;
        s1.insert(0), s2.insert(0);
        for (long long i = ind - 1; i >= 0; i--)
        {
            v1.push_back(a[i]);
            sum += a[i];
            s1.insert(sum);
            t1.push_back(-a[i]);
        }
        sum = 0;
        for (long long i = ind + 1; i < n; i++)
        {
            v2.push_back(a[i]);
            sum += a[i];
            s2.insert(sum);
            t2.push_back(-a[i]);
        }
        set<long long> ss;
        long long r1 = maxSubarraySum(v1);
        long long l1 = -maxSubarraySum(t1);
        long long r2 = maxSubarraySum(v2);
        long long l2 = -maxSubarraySum(t2);
        long long sl = a[ind];
        ss.insert(0);
        for (long long i = l1; i <= r1; i++)
            ss.insert(i);
        for (long long i = l2; i <= r2; i++)
            ss.insert(i);
        for (long long i = sl + *(s1.begin()) + *(s2.begin()); i <= sl + *(s1.rbegin()) + *(s2.rbegin()); i++)
            ss.insert(i);
        ss.insert(sl);
        cout << ss.size() << endl;
        for (auto it : ss)
        {
            cout << it << " ";
        }
        cout << endl;
    }
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