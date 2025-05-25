#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long count = 0;
    int curr = 0;
    long long prev = a[0];
    for (long long i = 1; i < n; i++)
    {
        int temp = a[i];
        while (temp >= 2 * a[i - 1] && curr)
        {
            temp /= 2;
            curr--;
        }
        while (temp < a[i - 1])
        {
            curr++;
            temp *= 2;
        }
        count += curr;
    }
    cout << count << endl;
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