#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(k);
    for (long long i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i] = k - a[i];
    }

    vector<bool> f(k);
    long long siz = 0;
    for (long long i = 0, j = 0; i < k; i++)
    {
        while (!f[i])
        {
            f[a[j++]] = true;
            siz++;
        }
        if (siz > n * m - 3)
        {
            cout << "TIDAK" << endl;
            return;
        }
        f[i] = false;
        siz--;
    }
    cout << "YA\n";
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