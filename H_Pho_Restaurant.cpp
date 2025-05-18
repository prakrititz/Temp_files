#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<string> tables(n);
    for (int i = 0; i < n; i++)
    {
        cin >> tables[i];
    }
    int ans = 0;
    int white = 0;
    int black = 0;
    vector<int> a(n);
    vector<int> b(n);
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        int one = 0;
        int zero = 0;
        for (int j = 0; j < tables[i].size(); j++)
        {
            if (tables[i][j] == '0')
                zero++;
            else
                one++;
        }
        a[i] = one;
        b[i] = zero;
        if (one > zero)
        {
            white++;
        }
        else if (zero > one)
        {
            black++;
        }
        else
        {
            flag = true;
        }
        ans += min(one, zero);
    }
    int actual = INT_MAX;
    if (black == 0 && *max_element(b.begin(), b.end()) != 0 && flag == false)
    {
        // everytime its white minority
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, abs(a[i] - b[i]));
        }
        ans += mini;
        cout << ans << endl;
    }
    else if (white == 0 && *max_element(a.begin(), a.end()) != 0 && flag == false)
    {
        // everytime its black minority
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, abs(a[i] - b[i]));
        }
        ans += mini;
        cout << ans << endl;
    }
    else
    {
        cout << ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}