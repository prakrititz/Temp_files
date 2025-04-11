#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> st;
    vector<int> ans(n);
    int curr = 0;
    st.push(a[0]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == st.top())
        {
            curr++;
        }
        if (a[i] < 0)
        {
            st.pop();
        }
        else
        {
            st.push(a[i]);
        }
        ans[i] = curr;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << ans[r] - ans[l] << endl;
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