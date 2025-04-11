    #include <bits/stdc++.h>
    using namespace std;

    void solve()
    {
        int n;
        int m;
        cin >> n;
        cin >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> prev(n);
        prev[0] = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                prev[i] = prev[i - 1];
            }
            else
            {
                prev[i] = i - 1;
            }
        }

        while (m--)
        {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;
            if (a[l] != x)
            {
                cout << l + 1 << endl;
            }
            else if (a[r] != x)
            {
                cout << r + 1 << endl;
            }
            else if (prev[r] >= l && a[prev[r]] != x)
            {
                cout << prev[r] + 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    int main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t;
        // cin >> t;
        t = 1;
        while (t--)
        {
            solve();
        }

        return 0;
    }