#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double n, m, h;
    cin >> n >> m >> h;
    vector<long double> a(m);
    long double total_players = 0;

    for (long double i = 0; i < m; i++) {
        cin >> a[i];
        total_players += a[i];
    }
    long double herr_wafa_department = a[h - 1];

    if (total_players < n) {
        cout << -1 << endl;
        return 0;
    }
    if (total_players == n && herr_wafa_department >= 2) {
        cout << 1 << endl;
        return 0;
    }
    if (herr_wafa_department <= 1) {
        cout << 0 << endl;
        return 0;
    }
    long double T = total_players;
    long double N  = n-1;
    long double  T1  = T-N;
    long double nunu = 1;
    long double denom = 1;
    for(long double i = 1; i<herr_wafa_department; i++)
    {   
        denom*=(T-i);
    }
    for(long double i = 1; i<herr_wafa_department; i++)
    {   
        nunu*=(T-N-i);
    }
    cout << 1.0 - nunu/denom<< endl;
    return 0;
}
