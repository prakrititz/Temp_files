#include <bits/stdc++.h>
using namespace std;
vector<long long> preCompute(500004, -1);
void solve()
{
    long long n;
    cin >> n;
    if (n == 1)
    {
        cout << -1 << endl;
        return;
    }
    else if (n == 2)
    {
        cout << 2 << " " << 1 << endl;
        return;
    }
    long long num = (n * (n + 1)) / 2;
    long long s = sqrt(num);
    if (s * s == num)
    {
        cout << -1 << endl;
        return;
    }
    else
    {
        vector<long long> ans(n + 1);
        ans[1] = 2;
        ans[2] = 1;
        for (long long i = 3; i <= n; i++)
        {
            if (preCompute[i] == 1)
            {
                // cout << "yess" << i << endl;
                ans[i] = i + 1;
                ans[i + 1] = i;
                i++;
            }
            else
            {
                ans[i] = i;
            }
        }
        for (long long i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    for (long long i = 1; i < preCompute.size(); i++)
    {
        long long num = (i * (i + 1)) / 2;
        long long s = sqrt(num);
        if (s * s == num)
        {
            preCompute[i] = 1;
        }
    }
    while (t--)
    {
        solve();
    }

    return 0;
}