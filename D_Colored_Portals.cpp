#include <bits/stdc++.h>
using namespace std;

void solve()
{
    vector<string> valid = {"BG", "BR", "BY", "GR", "GY", "RY"};
    int n, q;
    cin >> n >> q;

    vector<int> cit(n);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 6; j++)
        {
            string re = s;
            reverse(re.begin(), re.end());
            if (s == valid[j] || re == valid[j])
            {
                cit[i] = j;
                break;
            }
        }
    }

    vector<vector<int>> lnear(n, vector<int>(6, -INT_MAX));
    vector<vector<int>> rnear(n, vector<int>(6, -INT_MAX));
    vector<int> lastSeen(6, -INT_MAX);
    for (int i = 0; i < n; i++)
    {
        lastSeen[cit[i]] = i;
        lnear[i] = lastSeen;
    }

    lastSeen.assign(6, -INT_MAX);
    for (int i = n - 1; i >= 0; i--)
    {
        lastSeen[cit[i]] = i;
        rnear[i] = lastSeen;
    }

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        if (x == y)
        {
            cout << "0" << endl;
            continue;
        }

        if (cit[x] == cit[y])
        {
            cout << abs(x - y) << endl;
            continue;
        }
        if (cit[x] + cit[y] != 5)
        {
            cout << abs(x - y) << endl;
            continue;
        }
        int minCost = INT_MAX;
        for (int j = 0; j < 6; j++)
        {
            if (cit[x] + j != 5 && j + cit[y] != 5)
            {
                int leftCity = lnear[x][j];
                if (leftCity > -INT_MAX)
                {
                    int cost = abs(x - leftCity) + abs(leftCity - y);
                    minCost = min(minCost, cost);
                }

                int rightCity = rnear[x][j];
                if (rightCity > -INT_MAX)
                {
                    int cost = abs(x - rightCity) + abs(rightCity - y);
                    minCost = min(minCost, cost);
                }
            }
        }

        if (minCost >= INT_MAX / 2)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << minCost << endl;
        }
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