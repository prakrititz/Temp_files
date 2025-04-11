#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    string s = "";
    cin >> n;
    vector<char> d = {'1', '2', '3', '5', '6', '7', '8', '9', '0'};
    while (n)
    {
        int f = n % 9;
        n /= 9;
        if (f == 0)
            s += '0';
        else
            s += d[(f - 1) % 9];
        // cout << s << endl;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
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