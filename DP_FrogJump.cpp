#include <bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &heights)
{
    int left = f(ind - 1, heights) + abs(heights[ind] - heights[ind - 1]);
    int right = INT_MAX;
    if (ind > 1)
        int right = f(ind - 2, heights) + abs(heights[ind] - heights[ind - 2]);
    return min(left, right);
}
void solve()
{
    int n;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; i++)
        cin >> heights[i];
    int ans = f(n - 1, heights);
    cout << ans << endl;
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