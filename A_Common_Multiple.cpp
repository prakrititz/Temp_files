#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    set<int> ss;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ss.insert(x);
    }
    cout << ss.size() << endl;
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