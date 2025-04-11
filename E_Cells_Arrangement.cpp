#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 2)
    {
        cout << 1 << " " << 1 << endl;
        cout << 2 << " " << 2 << endl;
    }
    else if (n == 3)
    {
        cout << 1 << " " << 1 << endl;
        cout << 3 << " " << 3 << endl;
        cout << 1 << " " << 2 << endl;
    }
    else
    {

        cout << 1 << " " << 1 << endl;

        for (int i = 0; i < n - 3; i++)
        {
            cout << 1 << " " << 3 + i << endl;
        }
        cout << 2 << " " << 1 << endl;
        cout << n << " " << n << endl;
    }
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