#include <bits/stdc++.h>
using namespace std;

int check(int &gl, int &gr, int &pl, int &pr, int &sr)
{
    if ((pl >= 5 && pl - pr >= 2) || pl == 10)
    {
        gl++;
        pl = pr = 0;
        sr = 0;
        return 1;
    }
    if ((pr >= 5 && pr - pl >= 2) || pr == 10)
    {
        gr++;
        pl = pr = 0;
        sr = 1;
        return 2;
    }
    return 0;
};
void solve()
{
    string s;
    cin >> s;
    int gl = 0, gr = 0, pl = 0, pr = 0, sr = 0;
    bool over = 0;
    for (auto c : s)
    {
        if (c == 'S' && !over)
        {
            if (sr == 0)
                pl++;
            else
                pr++;
        }
        else if (c == 'R' && !over)
        {
            if (sr == 0)
                pr++;
            else
                pl++;
            sr ^= 1;
        }
        else if (c == 'Q')
        {
            if (over)
            {
                if (gl == 2)
                    cout << gl << " (winner) - " << gr << endl;
                else
                    cout << gl << " - " << gr << " (winner)" << endl;
            }
            else
            {
                cout << gl << " (" << pl;
                if (!over && sr == 0)
                    cout << "*";
                cout << ") - " << gr << " (" << pr;
                if (!over && sr == 1)
                    cout << "*";
                cout << ")" << endl;
            }
        }
        if (!over)
        {
            int winner = check(gl, gr, pl, pr, sr);
            if (winner)
            {
                if (winner == 1)
                    sr = 0;
                else
                    sr = 1;
                if (gl == 2 || gr == 2)
                    over = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}