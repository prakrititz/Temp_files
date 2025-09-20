#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
void solve()
{
    long long n;
    cin >> n;
    vector<vector<long long>> ch(n + 1);
    for (long long i = 2; i <= n; ++i)
    {
        long long p;
        cin >> p;
        ch[p].push_back(i);
    }

    vector<long long> order(n);
    vector<long long> st;
    st.push_back(1);
    while (!st.empty())
    {
        long long u = st.back();
        st.pop_back();
        order.push_back(u);
        for (long long v : ch[u])
            st.push_back(v);
    }
    reverse(order.begin(), order.end());

    vector<long long> dp1(n + 1), dp2(n + 1);
    for (long long u : order)
    {
        if (ch[u].empty())
        {
            // leaf
            dp1[u] = 1;
            dp2[u] = 1;
            continue;
        }
        long long k = (long long)ch[u].size();
        vector<long long> A(k), B(k);
        for (long long i = 0; i < k; ++i)
        {
            long long v = ch[u][i];
            A[i] = dp1[v];
            B[i] = dp2[v];
        }
        // prefix products of A
        vector<long long> pref(k + 1, 1), suf(k + 1, 1);
        for (long long i = 1; i <= k; ++i)
            pref[i] = pref[i - 1] * A[i - 1] % mod;
        for (long long i = k - 1; i >= 0; --i)
            suf[i] = suf[i + 1] * A[i] % mod;
        long long s1 = pref[k]; // product of all A
        long long s2 = 0;
        for (long long i = 0; i < k; ++i)
        {
            long long others = pref[i] * suf[i + 1] % mod;
            s2 += others * B[i] % mod;
            if (s2 >= mod)
                s2 -= mod;
        }
        dp1[u] = (s1 + s2) % mod;
        dp2[u] = s2 % mod;
    }
    cout << dp1[1] % mod << endl;
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