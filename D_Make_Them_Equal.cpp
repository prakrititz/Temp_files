#include <bits/stdc++.h>
using namespace std;

vector<int> operation(1001, INT_MAX);
void precompute()
{

    operation[1] = 0;
    for (int i = 1; i <= 1000; i++)
    {
        if (operation[i] == INT_MAX)
            continue;
        for (int range = 1; range <= i; range++)
        {
            int new_element = i + (i / range);
            if (new_element <= 1000)
            {
                operation[new_element] = min(operation[new_element], operation[i] + 1);
            }
        }
    }
}
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];
    k = min(operation[1000]*n, k);
    vector<long long> dp(k + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int cost = operation[b[i]];
        int value = c[i];
        {
            if (cost == 0)
            {
                for (int j = 0; j <= k; j++)
                {
                    dp[j] += value;
                }
            }
            else
            {
                for (int j = k; j >= cost; j--)
                {
                    dp[j] = max(dp[j], dp[j - cost] + value);
                }
            }
        }
    }
    cout << dp[k] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    precompute();
    while (t--)
    {
        solve();
    }

    return 0;
}