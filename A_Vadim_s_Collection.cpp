#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> ans;
    vector<int> cnt(11, 0);
    for (int i = 0; i < 10; i++)
    {
        cnt[s[i] - '0']++;
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 10 - (i + 1); j <= 9; j++)
        {
            if (cnt[j] > 0)
            {
                ans.push_back(j);
                cnt[j]--;
                break;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
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