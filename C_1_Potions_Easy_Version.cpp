
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    int count = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        count++;

        if (a[i] < 0)
        {
            pq.push(a[i]);
        }

        if (sum < 0)
        {
            sum -= pq.top();
            pq.pop();
            count--;
        }
    }

    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--)
    {
        solve();
    }

    return 0;
}