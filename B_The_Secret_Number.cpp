#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;

    vector<long long> ans;
    for (int k = 1; k <= 18; k++)
    {
        long long d = 1 + (long long)pow(10, k);
        if (n % d == 0)
        {
            long long x = n / d;
            ans.push_back(x);
        }
    }

    if (ans.empty())
    {
        cout << 0 << endl;
        return;
    }

    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
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
