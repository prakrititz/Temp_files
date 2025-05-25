#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    bool flag = false;
    stack<int> st;
    int val = 1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            st.push(val);
        else
        {
            st.pop();
            if (st.empty() && i < s.size() - 1)
                flag = true;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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