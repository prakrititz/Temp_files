#include <bits/stdc++.h>
using namespace std;

int check(int &GL, int &GR, int &PL, int &PR, int &server)
{
    if ((PL >= 5 && PL - PR >= 2) || PL == 10)
    {
        GL++;
        PL = PR = 0;
        server = 0;
        return 1;
    }
    if ((PR >= 5 && PR - PL >= 2) || PR == 10)
    {
        GR++;
        PL = PR = 0;
        server = 1;
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
            int winner = check(gl, gamesRight, pointsLeft, pointsRight, server);
            if (winner)
            {
                // winner serves next game
                server = (winner == 1 ? 0 : 1);
                if (gl == 2 || gamesRight == 2)
                    matchFinished = true;
            }
        }
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