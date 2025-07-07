#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n;
    cin >> n;
    long long p1, p2, p3, p4;
    cin >> p1 >> p2 >> p3 >> p4;

    vector<long long> a(n);
    long long s = 0;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    long long d = (p1 - p3) * (p1 - p3) + (p2 - p4) * (p2 - p4);
    long long mini = max(0LL, 2 * (*max_element(a.begin(), a.end())) - s);

    if (sqrt(d) > s || sqrt(d) < mini)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
