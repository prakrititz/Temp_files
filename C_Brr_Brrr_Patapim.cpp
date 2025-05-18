#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin >> n;

    vector<int> p(n * 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int g;
            cin >> g;
            p[i + j + 1] = g;
        }
    }
    p[0] = 2 * n * (2 * n + 1) / 2;
    int sum = accumulate(p.begin() + 1, p.end(), 0);
    p[0] -= sum;
    for (int i = 0; i < 2 * n; i++)
    {
        cout << p[i] << " ";
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