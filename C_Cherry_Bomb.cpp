#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (b[i] != -1)
        {
            mp[a[i] + b[i]]++;
        }
    }
    if (mp.size() == 1)
    {
        bool check = true;
        int val;
        for (auto it : mp)
            val = it.first;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == -1)
            {
                if (val - a[i] < 0 || val - a[i] > k)
                    check = false;
            }
        }
        if (check)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    else if (mp.size() == 0)
    {
        int mini = *min_element(a.begin(), a.end());
        int maxi = *max_element(a.begin(), a.end());
        cout << k - (maxi - mini) + 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
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