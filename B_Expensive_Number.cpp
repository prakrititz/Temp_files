#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int j = s.size() - 1;
    while (s[j] == '0')
        j--;
    int count = 0;
    for (int i = 0; i <= j; i++)
        if (s[i] == '0')
            count++;
    cout << s.size() - (count + 1) << endl;
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