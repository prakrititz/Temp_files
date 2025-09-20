#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int k;
    long long x;
    cin >> k >> x;
    long long S = 1LL << (k + 1);
    long long a = 1LL << k;
    long long c = x;
    vector<int> seq;
    while (c != a)
    {
        if (c < a)
        {
            seq.push_back(1);
            c = 2 * c;
        }
        else
        {
            seq.push_back(2);
            c = 2 * c - S;
        }
    }
    reverse(seq.begin(), seq.end());
    int n = seq.size();
    cout << n << endl;
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
                cout << ' ';
            cout << seq[i];
        }
        cout << endl;
    }
    else
    {
        cout << endl;
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