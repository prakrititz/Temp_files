#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    cin >> k;
    if (k == 1)
    {
        cout << "YES" << endl;
    }
    
    else if ((k-1) % 3 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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