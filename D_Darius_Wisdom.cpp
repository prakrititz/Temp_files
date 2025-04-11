#include <bits/stdc++.h>
using namespace std;

void swapp(vector<int> &a, vector<pair<int, int>> &ans, set<int> s[], int i, int j)
{
    ans.push_back({i + 1, j + 1});
    assert(abs(a[i] - a[j]) == 1);
    s[a[i]].erase(i);
    s[a[j]].erase(j);
    swap(a[i], a[j]);
    s[a[i]].insert(i);
    s[a[j]].insert(j);
}

vector<pair<int, int>> get(vector<int> a)
{
    int n = a.size();
    vector<pair<int, int>> ans;

    set<int> s[3];
    for (int i = 0; i < n; i++)
    {
        s[a[i]].insert(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (s[1].empty())
        {
            continue;
        }
        else if (s[0].empty())
        {
            if (a[i] == 2)
            {
                swapp(a, ans, s, i, *s[1].begin());
            }
        }
        else
        {
            if (a[i] == 2)
            {
                swapp(a, ans, s, i, *s[1].begin());
            }
            if (a[i] == 1)
            {
                swapp(a, ans, s, i, *s[0].begin());
            }
        }
        s[a[i]].erase(i);
    }
    return ans;
}

void solve()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<int, int>> ans = get(a);

    if (ans.size() > n)
    {
        reverse(a.begin(), a.end());
        for (int &x : a)
        {
            x = 2 - x;
        }
        ans = get(a);
        for (pair<int, int> &p : ans)
        {
            p.first = n + 1 - p.first;
            p.second = n + 1 - p.second;
        }
    }

    cout << ans.size() << endl;
    for (const pair<int, int> &p : ans)
    {
        cout << p.first << " " << p.second << endl;
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
