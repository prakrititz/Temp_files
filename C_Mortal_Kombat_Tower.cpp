#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<int>>> dp;

int solvee(vector<int> &a, int ind, int me, int him) {
    if (ind == 0) {
        if (me < 2)
            return 0;
        return (a[ind] == 1) ? 1 : 0;
    }
    if (dp[ind][me][him] != -1) return dp[ind][me][him];

    int mee, himm;
    if (me == 2) {
        himm = solvee(a, ind - 1, 0, 1) + (a[ind] == 1);
        return dp[ind][me][him] = himm;
    } 
    if (him == 2) {
        mee = solvee(a, ind - 1, 1, 0);
        return dp[ind][me][him] = mee;
    }

    mee = solvee(a, ind - 1, me + 1, 0);
    himm = solvee(a, ind - 1, 0, him + 1) + (a[ind] == 1);

    return dp[ind][me][him] = min(himm, mee);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n == 1) {
        cout << (a[0] == 1 ? 1 : 0) << endl;
        return;
    }

    reverse(a.begin(), a.end());
    dp.assign(n, vector<vector<int>>(3, vector<int>(3, -1)));

    int firstTry = (a[n - 1] == 1) ? 1 : 0;
    int ans = solvee(a, n - 2, 0, 1) + firstTry;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
