#include <bits/stdc++.h>
using namespace std;

long long query(long long x, const vector<long long> &S)
{
    cout << "? " << x << " " << S.size() << " ";
    for (long long i = 0; i < (long long)S.size(); i++)
    {
        cout << S[i] << " ";
    }
    cout << endl;
    cout.flush();
    long long ans;
    cin >> ans;
    return ans;
}

void solve_one_case()
{
    long long n;
    cin >> n;

    vector<long long> all;
    for (long long i = 1; i <= n; i++)
        all.push_back(i);

    vector<long long> len(n + 1, 1);
    for (long long x = 1; x <= n; x++)
    {
        len[x] = query(x, all);
    }

    long long start = 1;
    long long maxL = len[1];
    for (long long i = 2; i <= n; i++)
    {
        if (len[i] > maxL)
        {
            maxL = len[i];
            start = i;
        }
    }

    vector<vector<long long>> g(maxL + 1);
    for (long long v = 1; v <= n; v++)
    {
        if (len[v] >= 1 && len[v] <= maxL)
        {
            g[len[v]].push_back(v);
        }
    }

    vector<long long> ans;
    map<long long, long long> used;
    long long cur = start;
    ans.push_back(cur);
    used[cur] = 1;

    for (long long need = maxL - 1; need >= 1; need--)
    {
        long long nextv = -1;
        for (long long i = 0; i < (long long)g[need].size(); i++)
        {
            long long v = g[need][i];
            if (used[v])
                continue;
            vector<long long> S;
            S.push_back(cur);
            S.push_back(v);
            long long r = query(cur, S);

            if (r == 2)
            {
                nextv = v;
                break;
            }
        }
        ans.push_back(nextv);
        used[nextv] = 1;
        cur = nextv;
    }
    cout << "! " << ans.size() << " ";
    for (long long i = 0; i < (long long)ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long T;
    cin >> T;
    while (T--)
    {
        solve_one_case();
    }
    return 0;
}
