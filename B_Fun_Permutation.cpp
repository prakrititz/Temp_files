#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> q(n);
    for (int i = 0; i < n; i++)
    {
        q[i] = n + 1 - p[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << " ";
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
        solve();
}
