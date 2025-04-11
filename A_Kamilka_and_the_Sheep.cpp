#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
        maxi = max(maxi, a[i]);
        mini = min(mini, a[i]);
    }
    cout << maxi - mini << endl;
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