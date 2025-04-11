#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    queue<pair<int, int>> q;
    q.push({1, 0});
    int i = 1;
    int maxi = 0;
    while (i < n && !q.empty())
    {
        if (a[i] < a[i - 1])
        {
            q.pop();
            int lv2 = q.front().second;
            q.push({a[i], lv2 + 1});
            maxi = max(maxi, lv2 + 1);
            i++;
        }
        else
        {
            int p = q.front().first;
            int lv = q.front().second;
            while (a[i] > a[i - 1])
            {
                i++;
                q.push({a[i], lv + 1});
                maxi = max(maxi, lv + 1);
            }
        }
    }
    cout << maxi << endl;
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