#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n <= 3)
        cout << -1 << endl;
    else
    {
        vector<int> ans;
        if (n % 2)
        {
            int temp = n;
            while (temp > 1)
            {
                ans.push_back(temp);
                temp -= 2;
            }
            ans.push_back(1);
            ans.push_back(4);
            ans.push_back(2);
            if (n > 5)
            {
                for (int i = 6; i <= n; i += 2)
                    ans.push_back(i);
            }
        }
        else
        {
            int temp = n - 1;
            while (temp > 1)
            {
                ans.push_back(temp);
                temp -= 2;
            }
            ans.push_back(1);
            ans.push_back(4);
            ans.push_back(2);
            if (n > 5)
            {
                for (int i = 6; i <= n; i += 2)
                    ans.push_back(i);
            }
        }
        for (int i = 0; i < n; i++)
            cout << ans[i] << " ";
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