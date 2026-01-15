#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{ 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> p;
    for (int i = 0; i < n - 1; i++)p.push_back(abs(a[i] - a[i + 1]));
    int m = p.size();
    vector<int> l(m), r(m);
    stack<int> st;
    for (int i = 0; i < m; i++) {
        while (!st.empty() && p[st.top()] >= p[i])st.pop();
        if (st.empty())l[i] = -1;
        else l[i] = st.top();
        st.push(i);
    }
    while (!st.empty()) st.pop();
    for (int i = m - 1; i >= 0; i--) {
        while (!st.empty() && p[st.top()] > p[i]) st.pop();
        if (st.empty())r[i] = m;
        else r[i] = st.top();
        st.push(i);
    }
    vector<long long> ans(n + 2, 0);
    for (int i = 0; i < m; i++) {
        long long left = i - l[i];
        long long right = r[i] - i;
        ans[p[i]] += left * right;
    }
    for (int k = n - 2; k >= 1; k--)
        ans[k] += ans[k + 1];
    for (int k = 1; k <= n - 1; k++)
        cout << ans[k] << " ";
    cout <<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}