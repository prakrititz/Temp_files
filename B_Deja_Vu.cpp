#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    vector<int> x(q);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < q; i++)
        cin >> x[i];

    vector<int> f(30);
    for (int i = 0; i < 30; i++)
    {
        f[i] = pow(2, i);
    }
    for (int i = 0; i < q; i++)
    {
        int val = x[i];
        for (int i = 0; i < 30; i++)
        {
            if ((f[i] % (int)pow(2, val) == 0))
            {
                f[i] += pow(2, val - 1);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int x = 1, k = 0;
        while (a[i] % x == 0)
        {
            x *= 2;
            k++;
        }
        k--;
        a[i] += f[k] - pow(2, k);
        cout << a[i] << " ";
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