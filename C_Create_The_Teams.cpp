#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int count = 0;
    sort(a.rbegin(), a.rend());
    int currmin;
    int currsize = 0;
    for (int i = 0; i < n; i++)
    {
        currmin = a[i];
        currsize += 1;
        // cout << currmin << " " << currsize << endl;
        if (currsize * currmin >= x)
        {
            count++;
            currsize = 0;
        }
    }
    cout << count << endl;
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