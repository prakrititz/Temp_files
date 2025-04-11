#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canAchieve(const string &s, const vector<int> &penalties, int k, long long maxPenalty)
{
    int n = s.length();
    vector<bool> flag(n, false);

    // Mark cells that must be painted blue (those with penalty > maxPenalty)
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'B' && penalties[i] > maxPenalty)
        {
            flag[i] = true;
        }
    }

    int operations = 0;
    int i = 0;

    while (i < n)
    {
        if (flag[i])
        {
            operations++;
            // Skip all positions that will be covered by this operation
            i++;
            while (i < n && (flag[i] || ((!flag[i])&&(penalties[i]<=maxPenalty))))
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }

    return operations <= k;
}

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<int> penalties(n);
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> penalties[i];
        maxi = max(maxi, penalties[i]);
    }

    // Binary search on the maximum penalty
    long long left = 0, right = maxi;
    
    while (left < right)
    {
        long long mid = (left + right) / 2;
        // cout << mid << endl;
        if (canAchieve(s, penalties, k, mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << left << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}