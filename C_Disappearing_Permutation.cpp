#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> d(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for (long long i = 0; i < n; i++)
    {
        cin >> d[i];
        d[i]--;
    }

    vector<bool> vis(n, false);
    map<long long, long long> cycleid;
    map<long long, long long> cyclesize;
    long long id = 0;

    for (long long i = 0; i < n; i++)
    {
        if (vis[i])
            continue;

        long long cur = i;
        long long size = 0;
        vector<long long> temp;
        while (!vis[cur])
        {
            vis[cur] = true;
            temp.push_back(cur);
            cur = a[cur];
            size++;
        }
        for (long long num : temp)
        {
            cycleid[num] = id;
        }
        cyclesize[id] = size;
        id++;
    }
    vector<long long> handled(n + 1, 0);
    vector<long long> ans(n);
    long long total = 0;
    for (long long i = 0; i < n; i++)
    {
        long long node = d[i];
        if (handled[cycleid[node]])
        {
            ans[i] = total;
        }
        else
        {
            ans[i] = total + cyclesize[cycleid[node]];
            total += cyclesize[cycleid[node]];
            handled[cycleid[node]]++;
        }
    }
    for (long long i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
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