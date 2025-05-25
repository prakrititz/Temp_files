#include <bits/stdc++.h>
using namespace std;
vector<long long> fac[100001];

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int maxi = INT_MAX;
    int i = 0, j = 0;
    int count = 0;
    vector<int> cnt(m + 1);
    while (i < n && j <= n)
    {
        if (count < m && j < n)
        {
            for (int k = 0; k < fac[a[j]].size(); k++)
            {
                int val = fac[a[j]][k];
                if (val <= m)
                {
                    if (cnt[val] == 0)
                        count++;
                    cnt[val]++;
                }
            }
            j++;
        }
        else
        {
            if (count == m && j > i)
            {
                maxi = min(maxi, a[j - 1] - a[i]);
            }
            for (int k = 0; k < fac[a[i]].size(); k++)
            {
                int val = fac[a[i]][k];
                if (val <= m)
                {
                    if (cnt[val] == 1)
                        count--;
                    cnt[val]--;
                }
            }
            i++;
        }
    }
    if (maxi == INT_MAX)
        maxi = -1;
    cout << maxi << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1; i <= 100000; i++)
    {
        for (int j = i; j <= 100000; j += i)
        {
            fac[j].push_back(i);
        }
    }
    int t;
    cin >> t;
    int count = 0;
    while (t--)
    {
        count++;
        solve();
    }

    return 0;
}