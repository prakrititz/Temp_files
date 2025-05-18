    #include <bits/stdc++.h>
    using namespace std;

    void solve()
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        cout << a[n - 1 - (n - k - 1) / 2] - a[(n - k - 1) / 2] + 1 << endl;
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