#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
vector<long long> fact(200005, 1);
int CNT = 0;
long long modmul(long long a, long long b)
{
    return (a % MOD) * (b % MOD) % MOD;
}
void solve()
{
    long long n, m;
    cin >> n >> m;
    vector<vector<long long>> adj(n);
    vector<long long> deg(n);
    for (long long i = 0; i < m; i++)
    {
        long long x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if (m != n - 1)
    {
        cout << 0 << endl;
        return;
    }

    if (n == 2)
    {
        cout << 2 << endl;
        return;
    }

    long long ans = 4;
    for (int i = 0; i < n; i++)
    {
        for (auto x : adj[i])
        {
            if (adj[x].size() != 1)
            {
                deg[i]++;
            }
        }
        if (deg[i] > 2)
        {
            cout << 0 << endl;
            return;
        }
        if (adj[i].size() > 1)
        {
            ans = modmul(ans, fact[adj[i].size() - deg[i]]);
            if (deg[i] == 0)
            {
                ans = modmul(ans, 500000004);
            }
        }
    }

    cout << ans % MOD << endl;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (long long i = 1; i < (long long)fact.size(); i++)
        fact[i] = modmul(fact[i - 1], i);

    long long t;
    cin >> t;
    while (t--)
        solve();
}
