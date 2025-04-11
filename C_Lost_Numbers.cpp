#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<int> b = {4, 8, 15, 16, 23, 42};
    vector<int> a(7);
    map<int, pair<int, int>> mp;

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            mp[b[i] * b[j]] = {b[i], b[j]};
        }
    }

    vector<int> freq(100, 0);
    int q1, q2, q3, q4;

    cout << "? 1 6" << endl;
    cout.flush();
    cin >> q1;

    cout << "? 1 5" << endl;
    cout.flush();
    cin >> q2;

    cout << "? 1 4" << endl;
    cout.flush();
    cin >> q3;

    cout << "? 1 3" << endl;
    cout.flush();
    cin >> q4;

    int temp1 = mp[q1].first, temp2 = mp[q1].second;
    int temp3 = mp[q2].first, temp4 = mp[q2].second;
    freq[temp1]++;
    freq[temp2]++;
    freq[temp3]++;
    freq[temp4]++;

    int common = -1;
    for (int i = 0; i < freq.size(); i++)
    {
        if (freq[i] == 2)
        {
            common = i;
            break;
        }
    }

    a[1] = common;
    a[6] = q1 / common;
    a[5] = q2 / common;
    a[4] = q3 / common;
    a[3] = q4 / common;
    set<int> used = {a[1], a[3], a[4], a[5], a[6]};
    for (int num : b)
    {
        if (!used.count(num))
        {
            a[2] = num;
            break;
        }
    }

    cout << "! ";
    for (int i = 1; i <= 6; i++)
        cout << a[i] << " ";
    cout << endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }

    return 0;
}
