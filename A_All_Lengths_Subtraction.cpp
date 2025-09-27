#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int i = 0, j = -1;
    while (a[i] != n)
        i++;
    j = i;
    bool flag = true;

    for (int k = n - 1; k >= 1; k--)
    {
        if (i > 0 && a[i - 1] == k)
            i--;
        else if (j < n && a[j + 1] == k)
            j++;
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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