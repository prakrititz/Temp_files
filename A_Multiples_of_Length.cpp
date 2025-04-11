#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (n != 1)
    {
        cout << 1 << " " << 1 << endl;
        cout << -a[0] << endl;
        a[0] = 0;
        cout << 2 << " " << n << endl;

        for (long long i = 1; i < n; i++)
        {
            cout << (n - 1LL) * a[i] << " ";
            a[i] = (n - 1LL) * a[i] + a[i];
        }
        cout << endl;
        cout << 1 << " " << n << endl;
        for (long long i = 0; i < n; i++)
            cout << -a[i] << " ";
    }
    else
    {
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << 1 << endl;
        cout << 0 << endl;
        cout << 1 << " " << n << endl;
        cout << -a[0];
    }
    return 0;
}