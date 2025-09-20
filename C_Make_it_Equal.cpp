#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> S(n), T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> S[i];
        S[i] %= k;
        S[i] = min(S[i], k - S[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
        T[i] %= k;
        T[i] = min(T[i], k - T[i]);
    }
    sort(S.begin(), S.end());
    sort(T.begin(), T.end());

    if (S == T)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
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