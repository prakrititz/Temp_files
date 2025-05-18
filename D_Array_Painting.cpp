#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> m;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            m.push_back(1);
            while (a[i] == 1)
                i++;
            i--;
        }
        else if (a[i] == 0)
        {
            m.push_back(0);
        }
        else
        {
            m.push_back(2);
        }
    }
    int count = 0;
    n = m.size();
    // for (int i = 0; i < m.size(); i++)
    //     cout << m[i] << " ";
    // cout << endl;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (m[i] == 2)
        {
            if (b[i] == 1)
            {
                continue;
            }
            b[i] = 1;
            count++;
            int temp = i + 1;
            while (temp < n && m[temp] != 0)
            {
                b[temp] = 1;
                temp++;
            }
            if (temp < n)
                b[temp] = 1;
            temp = i - 1;
            while (temp >= 0 && m[temp] != 0)
            {
                b[temp] = 1;
                temp--;
            }
            if (temp >= 0)
                b[temp] = 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (m[i] == 1)
        {
            if (b[i] == 1)
            {
                continue;
            }
            b[i] = 1;
            count++;
            if (i - 1 >= 0 && b[i - 1] == 0)
            {
                b[i - 1] = 1;
            }
            else if (i + 1 < n)
            {
                b[i + 1] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] == 0)
            count++;
    }
    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}