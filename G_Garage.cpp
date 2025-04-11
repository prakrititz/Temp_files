#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a = {3, 5, 7, 8, 9};
    if (n <= 3)
    {
        cout << a[n - 1] << endl;
    }
    else
    {
        if (n % 3 == 1)
        {
            cout << ((n + 2) / 3) * 4 << endl;
        }
        else if (n % 3 == 2)
        {
            cout << ((n + 2) / 3) * 4 + 1 << endl;
        }
        else
        {
            cout << ((n + 2) / 3) * 4 + 3 << endl;
        }
    }
    cout << endl;
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