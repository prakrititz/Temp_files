#include <bits/stdc++.h>
using namespace std;
int query(const string &cmd)
{
    cout << cmd << endl;
    cout.flush();
    int resp;
    cin >> resp;
    return resp;
}

void solve()
{
    long long n;
    cin >> n;
    if (query("mul 999999999") == -1)
        return;

    if (query("digit") == -1)
        return;
    if (n != 81)
    {
        if (query("add " + to_string(n - 81)) == -1)
            return;
    }
    if (query("!") == -1)
        return;
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