#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, q;
    cin >> n >> q;
    map<int, int> mp;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]] = i + 1; // 1-based index
    }
    while (q--)
    {
        int l, r, k;
        cin >> l >> r >> k;
        if (mp[k] < l || mp[k] > r)
            cout << -1 << " ";
        else
        {
            int big = 0;
            int bigNumber_needs_to_stay = 0;
            int small = 0;
            int smallNumber_needs_to_stay = 0;
            int actualPos = mp[k];
            int current_l = l;
            int current_r = r;
            while (current_l < current_r)
            {
                int mid = (current_l + current_r) / 2;
                if (actualPos == mid)
                    break;
                else if (actualPos > mid)
                {
                    if (a[mid - 1] > k)
                        small++;
                    else
                    {
                        smallNumber_needs_to_stay++;
                    }
                    current_l = mid + 1;
                }
                else
                {
                    if (a[mid - 1] < k)
                        big++;
                    else
                    {
                        bigNumber_needs_to_stay++;
                    }
                    current_r = mid - 1;
                }
            }
            k--;
            if (small + smallNumber_needs_to_stay > k || big + bigNumber_needs_to_stay > n - 1 - k)
            {
                cout << -1 << "  ";
                continue;
            }
            else
            {
                cout << max(small, big) * 2 << " ";
            }
        }
    }
    cout << endl;
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