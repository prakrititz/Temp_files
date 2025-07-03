#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<string, int> fq;
    while (q--)
    {
        string x, y;
        cin >> x >> y;
        string t = x + y;
        if (t == "ba")
        {
            if (fq["cb"])
            {
                fq["cb"]--;
                fq["cba"]++;
            }
            else
            {
                fq["ba"]++;
            }
        }
        else if (t == "ca")
        {
            if (fq["bc"])
            {
                fq["bc"]--;
                fq["bca"]++;
            }
            else
            {
                fq["ca"]++;
            }
        }
        else
        {
            fq[t]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a')
            continue;
        else if (s[i] == 'b')
        {
            if (fq["ba"])
            {
                fq["ba"]--;
                s[i] = 'a';
            }
            else if (fq["cba"])
            {
                fq["cba"]--;
                fq["cb"]++;
                s[i] = 'a';
            }
            else if (fq["bca"])
            {
                fq["bca"]--;
                s[i] = 'a';
            }
        }
        else if (s[i] == 'c')
        {
            if (fq["ca"])
            {
                fq["ca"]--;
                s[i] = 'a';
            }
            else if (fq["bca"])
            {
                fq["bca"]--;
                fq["bc"]++;
                s[i] = 'a';
            }
            else if (fq["cba"])
            {
                fq["cba"]--;
                s[i] = 'a';
            }
            else if (fq["cb"])
            {
                fq["cb"]--;
                s[i] = 'b';
            }
        }
    }
    cout << s << endl;
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