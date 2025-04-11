#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k == 2 && n == 1)
        cout << "YES" << endl;
    else if (k != 1)
        cout << "NO" << endl;
    else
    {
        bool t = false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0 && i != 1 && i != n)
                t = true;
        }
        if (t || n==1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
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