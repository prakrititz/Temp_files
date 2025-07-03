#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int cnt = 0;
    int i = 0;
    int k = m - 1;
    while (cnt < n)
    {   
        int val1 = a[i], val2 = a[k];
        for (int j = 0; j < 6; j++)
        {
            if (j % 2)
                cout << val1 << " ";
            else
                cout << val2 << " ";
        }
        cout << endl;
        cnt++;
        if (cnt == n)
            break;
        for (int j = 0; j < 6; j++)
        {
            if (j % 2)
                cout << val2 << " ";
            else
                cout << val1 << " ";
        }
        cnt++;
        i++, k--;
        cout << endl;
        if (cnt == n)
            break;
    }
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