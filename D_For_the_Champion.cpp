#include <bits/stdc++.h>
using namespace std;
const long long BIG = 1000000000LL;

void solve()
{
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    long long maxi = LLONG_MIN;
    long long max_xmy = LLONG_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, x[i] + y[i]);
        max_xmy = max(max_xmy, x[i] - y[i]);
    }
    long long d1;
    cout << "? U " << BIG << endl;
    cin >> d1;
    cout << "? R " << BIG << endl;
    cin >> d1;
    cout << "? U " << BIG << endl;
    cin >> d1;
    cout << "? R " << BIG << endl;
    cin >> d1;
    long long d2;
    cout << "? D " << BIG << endl;
    cin >> d2;
    cout << "? D " << BIG << endl;
    cin >> d2;
    cout << "? D " << BIG << endl;
    cin >> d2;
    cout << "? D " << BIG << endl;
    cin >> d2;
    long long X = (d2 + max_xmy + d1 + maxi - 8 * 1e9) / 2;
    long long Y = (d1 + maxi - d2 - max_xmy) / 2;
    cout << "! " << X << " " << Y << endl;
    cout.flush();
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
