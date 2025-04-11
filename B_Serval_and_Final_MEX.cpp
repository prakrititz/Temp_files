#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            x.push_back(i);
        }
    }
    if (x.size() == 0)
    {
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else if (x.size() == 1)
    {
        if (x.back() == n - 1)
        {
            cout << 2 << endl;
            cout << 2 << " " << n << endl;
            cout << 1 << " " << 2 << endl;
        }
        else                      
        {
            cout << 2 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
    }
    else
    {
        if (x.back() == n - 1)
        {
            if (x[0] != 0)
            {
                cout << 2 << endl;
                cout << 2 << " " << n << endl;
                cout << 1 << " " << 2 << endl;
            }
            else
            {
                cout << 3 << endl;
                cout << 1 << " " << n - 2 << endl;
                cout << 2 << " " << 3 << endl;
                cout << 1 << " " << 2 << endl;
            }
        }
        else
        {
            cout << 2 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << 2 << endl;
        }
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