#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    int s;
    cin >> n >> s;

    vector<int> a(19, 0);
    long long temp = n;
    int curr = 0;

    for (int i = 0; i < 19; ++i)
    {
        a[i] = temp % 10;
        temp /= 10;
        curr += a[i];
    }

    if (curr <= s)
    {
        cout << 0 << "\n";
        return;
    }

    int i = 0;

    while (curr > s)
    {

        if (a[i] == 0)
        {
            ++i;
            continue;
        }

        curr -= a[i];

        a[i] = 0;
        int curp = i + 1;
        while (true)
        {
            if (a[curp] == 9)
            {
                a[curp] = 0;
                curr -= 9;
                curp++; // i skip two
            }
            else
            {
                a[curp]++;
                curr++;
                break;
            }
        }

        i++;
    }

    long long ne = 0;
    for (int i = 18; i >= 0; --i)
    {
        ne = 10 * ne + a[i];
    }

    cout << ne - n << "\n";
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