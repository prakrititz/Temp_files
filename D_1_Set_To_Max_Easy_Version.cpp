#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << endl;
            return;
        }
    }
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            bool rf = false;
            for (int j = i; j < n; j++)
            {
                if (b[j] < b[i] || a[j] > b[i])
                    break;
                if (a[j] == b[i])
                {
                    rf = true;
                }
            }
            if (rf)
                continue;
            else
            {
                bool lf = false;
                for (int j = i; j >= 0; j--)
                {
                    if (b[j] < b[i] || a[j] > b[i])
                        break;
                    if (a[j] == b[i])
                    {
                        lf = true;
                    }
                }
                if (lf == false)
                    flag = false;
            }
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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