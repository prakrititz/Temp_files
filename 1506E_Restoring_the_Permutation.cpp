#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<int> s;
    vector<int> minimal(n, -1);
    vector<int> maximal(n, -1);
    set<int> used;
    for (int i = 1; i <= n; i++)
        used.insert(i);

    for (int i = 0; i < n; i++)
    {
        if (s.find(a[i]) == s.end()) // FIX: Use s.find() instead of std::find()
        {
            minimal[i] = a[i];
            maximal[i] = a[i];
            s.insert(a[i]);
            used.erase(a[i]);
        }
    }

    int curr = 1;
    for (int i = 0; i < n; i++)
    {
        if (minimal[i] == -1)
        {
            while (s.find(curr) != s.end())
                curr++;
            if (curr <= n)
                minimal[i] = curr++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (maximal[i] == -1)
        {
            auto it = used.upper_bound(a[i]);
            if (it != used.begin())
            {
                --it;
            }
            maximal[i] = *it;
            used.erase(*it);
        }
    }

    for (int i = 0; i < minimal.size(); i++)
        cout << minimal[i] << " ";
    cout << endl;
    for (int i = 0; i < minimal.size(); i++)
        cout << maximal[i] << " ";
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
