#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    map<int, int> got;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
        s.insert(a[i]);
    }
    vector<int> days;
    for (auto it : s)
        days.push_back(it);
    reverse(days.begin(), days.end());
    bool flag = false;
    for (int i = 0; i < days.size(); i++)
    {
        int curr = days[i];
        int d1 = curr + 1;
        int d2 = curr + 2;
        if (mp[curr] >= 4)
        {
            flag = true;
            break;
        }
        else if (mp[curr] == 3)
        {
            if (got[d2])
                flag = true;
            else
            {
                got[d1]++;
                got[d2]++;
            }
        }
        else if (mp[curr] == 2)
        {
            if (got[d2])
            {
                flag = true;
            }
            else
            {
                got[d1]++;
            }
        }
        else if (mp[curr] == 1)
        {
            if (got[d2])
            {
                got[d1]++;
            }
            else
            {
                got[d1] = 0;
                got[d2] = 0;
            }
        }
    }
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
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