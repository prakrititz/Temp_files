#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int maxi = *max_element(a.begin(), a.end());
    int mini = *min_element(a.begin(), a.end());
    if (maxi == mini)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == maxi)
            cout << 1 << " ";
        else
            cout << 2 << " ";
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