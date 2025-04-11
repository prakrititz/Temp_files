#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, long double>> ps;
    int maxi = 1;
    map<int, int> de;
    for (int i = 0; i < n; i++)
    {
        maxi = max(a[i], maxi);
        if (maxi == i + 1)
        {
            de[i + 1]++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int r;
        long double p;
        cin >> r >> p;
        ps.push_back({r, p});
    }
    bool flag = true;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
            flag = false;
    }
    int dd = 1;
    for (int i = 1; i <= n; i++)
    {
        if (de[i] == 0)
            dd = i;
    }
    long double ans = 0;
    long double mk = 1;
    for (int i = 0; i < m; i++)
    {
        int r = ps[i].first;
        long double p = ps[i].second;
        if (de[r] && r >= dd)
        {
            ans += mk * p;
            mk = mk * (1 - p);
        }
    }
    if (flag)
    {
        printf("1.000000\n");
        return;
    }
    int masxi = ps[0].first;
    for (int i = 0; i < m; i++)
    {
        masxi = max(ps[i].first, masxi);
    }
    if (masxi < dd)
    {
        printf("0.000000\n");
        return;
    }
    printf("%.6Lf\n", ans);
}

int main() {
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