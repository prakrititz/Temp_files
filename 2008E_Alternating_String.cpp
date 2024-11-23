#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int res = n;

        if (n % 2 == 0)
        {
            vector<vector<int>> v(2, vector<int>(26, 0));
            for (int i = 0; i < n; i++)
            {
                v[i % 2][s[i] - 'a']++;
            }
            for (int i = 0; i < 2; i++)
            {
                int mx = *max_element(v[i].begin(), v[i].end());
                res -= mx;
            }
            cout << res << endl;
        }
        else
        {
            vector<vector<int>> pref(2, vector<int>(26, 0));
            vector<vector<int>> suf(2, vector<int>(26, 0));

            for (int i = n - 1; i >= 0; i--)
            {
                suf[i % 2][s[i] - 'a']++;
            }

            for (int i = 0; i < n; i++)
            {
                suf[i % 2][s[i] - 'a']--;
                int ans = n;
                for (int k = 0; k < 2; k++)
                {
                    int mx = 0;
                    for (int j = 0; j < 26; j++)
                    {
                        mx = max(mx, suf[1 - k][j] + pref[k][j]);
                    }
                    ans -= mx;
                }
                res = min(res, ans);
                pref[i % 2][s[i] - 'a']++;
            }
            cout << res << endl;
        }
    }
    return 0;
}
