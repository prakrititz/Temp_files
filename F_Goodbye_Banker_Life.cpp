#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    n -= 1;
    int k;
    cin >> k;
    vector<int> sierpinskiRow(int n);
    vector<int> row(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        if ((n & i) == i)   
        {
            row[i] = k;
        }
    }
    for (int i = 0; i < row.size(); i++)
        cout << row[i] << " ";
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