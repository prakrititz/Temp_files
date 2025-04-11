#include <bits/stdc++.h>
using namespace std;


int prefix_or(int r)
{
    int res = 0;
    for (int i = 0; i < r; i++)
    {
        res |= i;
    }
    return res;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int mmax = n + 1;
    for (int m = 0; m <= n + 1; m++)
    {
        if (m & (~x))
        {
            mmax = m;
            break;
        }
    }

    vector<int> ans;
    if (n < mmax)
    {
        int baseOr = prefix_or(n);
        if (baseOr == x)
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }
        }
        else
        {
            int baseOr2 = prefix_or(n - 1);
            int missing = x & (~baseOr2);
            for (int i = 0; i < n - 1; i++)
            {
                ans.push_back(i);
            }
            ans.push_back(missing);
        }
    }
    else
    {
        int preOr = prefix_or(mmax);
        if (preOr == x)
        {
            for (int i = 0; i < mmax; i++)
            {
                ans.push_back(i);
            }
            for (int i = 0; i < n - mmax; i++)
            {
                ans.push_back(0);
            }
        }
        else
        {
            int missing = x & (~preOr);
            if (n == mmax)
            {
                int baseOr2 = prefix_or(mmax - 1);
                missing = x & (~baseOr2);
                for (int i = 0; i < mmax - 1; i++)
                {
                    ans.push_back(i);
                }
                ans.push_back(missing);
            }
            else
            {
                for (int i = 0; i < mmax; i++)
                {
                    ans.push_back(i);
                }
                ans.push_back(missing);
                for (int i = 0; i < n - mmax - 1; i++)
                {
                    ans.push_back(0);
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << (i + 1 == n ? "\n" : " ");
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