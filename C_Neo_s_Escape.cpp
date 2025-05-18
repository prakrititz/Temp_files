#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
            a.push_back(x);
        else if (a.back() != x)
            a.push_back(x);
    }
    int count = 0;
    if (a.size() == 1)
        count = 1;
    else
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (i == 0)
            {
                if (a[i] > a[i + 1])
                    count++;
            }
            else if (i == a.size() - 1)
            {
                if (a[i] > a[i - 1])
                    count++;
            }
            else
            {
                if (a[i] > a[i - 1] && a[i] > a[i + 1])
                    count++;
            }
        }
    }
    cout << count << endl;
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