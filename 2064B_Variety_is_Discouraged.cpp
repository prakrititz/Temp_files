#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]]++;
    }
    int maxLen = 0;
    int st = -1;
    int end = -1;
    int ansR;
    int ansL;
    for (int i = 0; i < n; i++)
    {
        if (mp[a[i]] == 1)
        {
            if (st == -1)
                st = i;
        }
        else
        {
            // i will move forward
            if (st != -1)
            {
                int len = i - st;
                if (len > maxLen)
                {
                    maxLen = len;
                    ansL = st;
                    ansR = i - 1;
                }
                st = -1;
            }
        }
    }
    if (st != -1)
    {
        int len = n - st;
        if (len > maxLen)
        {
            maxLen = len;
            ansL = st;
            ansR = n - 1;
        }
    }
    if (maxLen > 0)
    {
        cout << ansL + 1 << " " << ansR + 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
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