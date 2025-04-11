#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int single = 0;
    int mingle = 0;
    int count = 0;
    vector<char> ans(n);
    for (auto it : mp)
    {
        if (it.second == 1)
            single++;
        if (it.second >= 3)
            mingle++;
        count++;
    }
    if (single % 2 == 0 && single != 0)
    {
        cout << "YES" << endl;
        int alt = 1;
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i]] == 1)
            {
                if (alt == 1)
                {
                    ans[i] = 'A';
                    alt *= -1;
                }
                else
                {
                    ans[i] = 'B';
                    alt *= -1;
                }
            }
            else
            {
                ans[i] = 'B';
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i];
        cout << endl;
    }
    else if (single == 0)
    {
        if (count > 1)
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == a[0])
                    ans[i] = 'A';
                else
                    ans[i] = 'B';
            }
            for (int i = 0; i < n; i++)
                cout << ans[i];
            cout << endl;
        }
        else
        {

                cout << "YES" << endl;
                for (int i = 0; i < n; i++)
                    ans[i] = 'A';
                for (int i = 0; i < n; i++)
                    cout << ans[i];
                cout << endl;
        }
    }
    else
    {
        if (mingle >= 1)
        {
            cout << "YES" << endl;
            int alt = 1;
            int flag = 0;
            for (int i = 0; i < n; i++)
            {
                if (mp[a[i]] == 1)
                {
                    if (alt == 1)
                    {
                        ans[i] = 'A';
                        alt *= -1;
                    }
                    else
                    {
                        ans[i] = 'B';
                        alt *= -1;
                    }
                }
                else if (mp[a[i]] >= 3 && flag == 0)
                {
                    ans[i] = 'B';
                    flag = 1;
                }
                else
                {
                    ans[i] = 'A';
                }
            }
            for (int i = 0; i < n; i++)
                cout << ans[i];
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}