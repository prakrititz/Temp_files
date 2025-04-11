#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;

    long long first_zero = -1;
    int pos = x;
    for (int i = 0; i < min(k, n); i++)
    {
        if (s[i] == 'L')
            pos--;
        else
            pos++;

        if (pos == 0)
        {
            first_zero = i + 1;
            break;
        }
    }

    if (first_zero == -1)
    {
        cout << 0 << endl;
        return;
    }

    long long zero_count = 1;
    long long time = first_zero;
    if (time >= k)
    {
        cout << 1 << endl;
        return;
    }

    pos = 0;
    int len = 0;
    bool will_reach_zero_again = false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L')
            pos--;
        else
            pos++;

        len++;
        if (pos == 0)
        {
            will_reach_zero_again = true;
            break;
        }
    }

    if (!will_reach_zero_again)
    {
        cout << 1 << endl;
        return;
    }

    long long rem = k - time;
    zero_count += rem / len;

    rem %= len;

    if (rem > 0)
    {
        pos = 0;
        for (int i = 0; i < rem; i++)
        {
            if (s[i % n] == 'L')
                pos--;
            else
                pos++;

            if (pos == 0 && i > 0)
            {
                zero_count++;
            }
        }
    }

    cout << zero_count << endl;
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