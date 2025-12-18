#include <bits/stdc++.h>
using namespace std;

int n, tq = 0;

int query(int i, int j, int k)
{
    if (tq >= 75)
        return -1;
    cout << "? " << i << " " << j << " " << k << endl;
    cout.flush();

    int response;
    cin >> response;
    if (response == -1)
        exit(0);
    tq++;

    return response;
}

void solve()
{
    cin >> n;
    tq = 0;
    vector<int> qus = {1, 2, 3};
    int i = 0;

    while (tq < 75)
    {
        int ins = query(qus[0], qus[1], qus[2]);
        if (ins == 0)
        {
            cout << "! " << qus[0] << " " << qus[1] << " " << qus[2] << endl;
            cout.flush();
            return;
        }

        bool found = false;
        vector<vector<int>> comb;

        for (int i = 0; i < 3; i++)
        {
            vector<int> temp = qus;
            temp[i] = ins;
            comb.push_back(temp);
        }

        for (int i = 0; i < 3 && tq < 75; i++)
        {
            int qu = query(comb[i][0], comb[i][1], comb[i][2]);
            if (qu == 0)
            {
                qus = comb[i];
                found = true;
                break;
            }
        }
        if (!found)
        {
            qus = comb[i];
            i = (i + 1) % 3;
        }
    }

    cout << "! " << qus[0] << " " << qus[1] << " " << qus[2] << endl;
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
