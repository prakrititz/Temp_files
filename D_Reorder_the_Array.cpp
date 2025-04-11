#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int count = 0;
    int i = 0;
    int j = 1;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    while (i < j && j < n)
    {
        if (a[i] < a[j])
        {
            j++;
            i++;
            count++;
        }
        else
        {
            j++;
        }
    }
    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}