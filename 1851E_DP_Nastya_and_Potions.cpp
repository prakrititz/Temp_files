#include <bits/stdc++.h>
using namespace std;

long long find_cost(long long curr, vector<long long>&buys, vector<long long>&owned, vector<vector<long long>>&mix, vector<long long>&dp)
{

    if(dp[curr]!=-1)return dp[curr];
    if(mix[curr].empty())return buys[curr];
    long long mix_cost = 0;
    for(long long i =0 ;i<mix[curr].size(); i++)
    {
        mix_cost += find_cost(mix[curr][i]-1, buys, owned, mix, dp);
    }
    return dp[curr] = min(mix_cost, buys[curr]);
}

void solve()
{
    long long n, k;
    cin >> n >> k;

    vector<long long> buys(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> buys[i];
    }
    vector<long long> owned(k);
    for (long long i = 0; i < k; i++)
    {
        cin >> owned[i];
    }

    vector<vector<long long>> mix(n);
    for (long long i = 0; i < n; i++)
    {
        long long cost;
        cin >> cost;
        while (cost--)
        {
            long long x;
            cin >> x;
            mix[i].push_back(x);
        }
    }

    vector<long long> dp(n, -1);
    for (long long i = 0; i < owned.size(); i++)
    {
        dp[owned[i] - 1] = 0;
    }
    for (long long i = 0; i < n; i++)
    {
        cout << find_cost(i, buys, owned, mix, dp) << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}