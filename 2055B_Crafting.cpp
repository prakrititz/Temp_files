#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll t;
    cin >> t; // Number of test cases
    while (t--)
    {
        ll n;
        cin >> n; // Number of elements in the arrays
        vector<ll> a(n), b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i]; 

        ll rm = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < b[i])
            {
                ll diff = b[i] - a[i];
                a[i] += 2 * diff;
                rm += diff;   
            }
        }

        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            a[i] -= rm;
            if (a[i] < 0 || a[i] < b[i])
            {
                possible = false; 
                break;
            }
        }

        if (possible)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }
    return 0;
}
