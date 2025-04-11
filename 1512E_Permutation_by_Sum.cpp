#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    int m = r - l + 1;
    int mini = (m * (m + 1)) / 2;
    int maxi = (m * (2 * n - m + 1)) / 2;

    if (s < mini || s > maxi)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> ans(n, 0);
    set<int> ss;

    for (int i = 1; i <= n; i++)
    {
        ss.insert(i);
    }

    int put = n;
    int curr = 0;

    for (int i = l - 1; i <= r - 1; i++)
    {
        int rr = r - i - 1;
        while (put > 0 && !((s - (put + curr) >= (rr * (rr + 1)) / 2) &&
                            (s - (put + curr) <= (rr * (2 * put - rr + 1)) / 2)))
        {
            put--;
        }
        ans[i] = put;
        ss.erase(put);
        curr += put;
        put--;
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == 0)
        {
            ans[i] = *ss.begin();
            ss.erase(ss.begin());
        }
    }

    for (int num : ans)
    {
        cout << num << " ";
    }
    cout << endl;
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
