#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    long long k;
    cin >> k;
    long long n = s.size();
    long long sum = n;
    long long len = n;
    while (sum < k)
    {
        sum += len - 1;
        len--;
    }
    long long pos = (len - 1) - (sum - k);
    string t = "";
    long long x = n - len;
    for (auto c : s)
    {
        // cout << t << endl;
        while (x > 0 && !t.empty() && c < t.back())
        {
            t.pop_back();
            x--;
        }
        t += c;
    }
    // cout << t << endl;
    cout << t[pos];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}