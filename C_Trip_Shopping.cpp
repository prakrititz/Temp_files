#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n; i++)
        cin >> a[i];
    for (long long i = 0; i < n; i++)
        cin >> b[i];
    vector<pair<long long, long long>> ls;
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            ls.push_back({b[i], a[i]});
        }
        else
        {
            ls.push_back({a[i], b[i]});
        }
        ans += abs(a[i] - b[i]);
    }
    sort(ls.begin(), ls.end());
    long long mini = INT_MAX;
    for (long long i = 0; i < n - 1; i++)
    {
        if (ls[i].second > ls[i + 1].first)
        {
            cout << ans<< endl;
            return;
        }
        mini = min(mini, 2 * (ls[i + 1].first - ls[i].second));
    }
    cout << ans + mini << endl;
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