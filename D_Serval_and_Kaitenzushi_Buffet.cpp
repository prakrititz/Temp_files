#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<int> s;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        s.insert(-1 * a[i]);
        if ((n - i) % (k + 1) == 0)
        {
            auto it = s.begin();
            ans += -1 * (*it);
            s.erase(it);
        }
    }
    cout << ans << endl;
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