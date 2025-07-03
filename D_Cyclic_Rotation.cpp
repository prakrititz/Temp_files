#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> cnt(n + 1, 0);
    int i = 0;
    int j = 0;
    bool flag = true;
    while (j < n)
    {
        if (j < n && i < n && (a[i] == b[j]))
        {
            i++, j++;
            continue;
        }
        if (cnt[b[j]] > 0 && b[j] == b[j - 1])
        {
            cnt[b[j]]--;
            j++;
        }
        else if (i < n)
        {
            cnt[a[i]]++;
            i++;
        }
        else
        {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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