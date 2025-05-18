#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int first = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            first++;
        }
    }
    if (first == 2)
    {
        if (s[0] == '0')
            first--;
    }
    else if (first > 2)
        first = 2;
    else if (first == 1)
    {
        if (s[0] == '0')
            first = 0;
    }
    int score = 0;
    char cur = '0';
    for (int i = 0; i < n; i++)
    {
        if (s[i] == cur)
            score++;
        else
        {
            score += 2;
            cur = s[i];
        }
    }
    cout << score - first << endl;
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