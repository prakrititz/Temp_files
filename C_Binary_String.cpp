#include <bits/stdc++.h>
using namespace std;
bool can(const vector<int> &pos, int m)
{
    int k = pos.size();
    int x = k - m;
    for (int i = 0; i <= m; i++)
    {
        int l = pos[i];
        int r = pos[i + x - 1];
        if (r - l + 1 - x <= m)
        {
            return true;
        }
    }
    return false;
}
void solve()
{
    string s;
    cin >> s;
    vector<int> pos;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            pos.push_back(i);
        }
    }
    int l = 0;
    int r = pos.size();
    while (r - l > 1)
    {
        int mid = (l + r) / 2;
        if (can(pos, mid))
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    if (pos.empty() || pos.back() - pos[0] == pos.size() - 1)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << r << endl;
    }
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