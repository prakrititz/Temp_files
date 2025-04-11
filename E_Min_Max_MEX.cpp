#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> &a, int k, int m)
{
    if (m == 0)
        return true;

    int n = a.size();
    vector<bool> vis(m, false);
    int needed = m;
    int found = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] < m && !vis[a[i]])
        {
            vis[a[i]] = true;
            needed--;
            if (needed == 0)
            {
                found++;
                fill(vis.begin(), vis.end(), false);
                needed = m;
            }
        }
    }

    return found >= k;
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int l = 0;
    int r = n;
    int ans;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        // cout << l << " " << r << " " << mid << endl;
        if (check(a, k, mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
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