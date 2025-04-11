#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    if (count(s.begin(), s.end(), s[0]) == n)
    {
        cout << -1 << endl;
        return;
    }

    vector<int> a(n);
    int cnt[3]{};
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
        {
            a[i] = 0;
        }
        else if (s[i] == 'I')
        {
            a[i] = 1;
        }
        else
        {
            a[i] = 2;
        }
        cnt[a[i]]++;
    }

    vector<int> ans;
    int min = *min_element(cnt, cnt + 3);
    for (int x = 0; x < 3; x++)
    {
        if (cnt[x] == min)
        {
            continue;
        }
        int p = 1;
        while ((a[p] == x) == (a[p - 1] == x))
        {
            p++;
        }
        while (cnt[x] > min)
        {
            if (a[p] == x)
            {
                int y = a[p - 1];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p + 1, y);
                ans.push_back(p + 1);
                p += 2;
            }
            else
            {
                
                int y = a[p];
                a.insert(a.begin() + p, 3 - x - y);
                ans.push_back(p);
                a.insert(a.begin() + p, y);
                ans.push_back(p);
                
            }
            cnt[x]--;
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
    {
        cout << x << endl;
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