#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        long long int mine = INT_MAX, maxe = 0;
        long long int min_cost = 0, max_cost = 0;
        long long int max_len = 0, len_cost = 0;
        long long ans;
        for (long long i = 0; i < n; i++)
        {
            long long l, r, c;
            cin >> l >> r >> c;
            if (l < mine)
                mine = l, min_cost = c;
            else if (l == mine)
                min_cost = min(c, min_cost);

            if (r > maxe)
                maxe = r, max_cost = c;
            else if (r == maxe)
                max_cost = min(c, max_cost);

            if (max_len < (r - l + 1))
                max_len = (r - l + 1), len_cost = c;
            else if (max_len == (r - l + 1))
                len_cost = min(c, len_cost);

            ans = min_cost + max_cost;
            if (max_len == (maxe - mine + 1))
                ans = min(len_cost, ans);

            cout << ans << endl;
        }
    }
    return 0;
}