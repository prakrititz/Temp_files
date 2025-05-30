#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto itr = max_element(a.begin(), a.end()) - a.begin();
    int sum = accumulate(a.begin(), a.end(), 0ll);
    a[itr]--;
    int maxi = *max_element(a.begin(), a.end());
    int mini = *min_element(a.begin(), a.end());
    if (abs(maxi - mini) > k)
    {
        cout << "Jerry" << endl;
        return;
    }
    if (sum % 2)
        cout << "Tom" << endl;
    else
        cout << "Jerry" << endl;
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