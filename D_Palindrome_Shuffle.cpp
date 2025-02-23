#include <bits/stdc++.h>
using namespace std;

bool check(string s, int mid)
{
    long long n = s.size();
    for (long long i = mid; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
            return false;
    }
    vector<int> freq(26, 0);
    for (int i = 0; i < mid; i++)
    {
        freq[s[i]-'a']++;
    }
    for (long long i = n - 1; i >= mid && i >= n - mid; i--)
    {
        if (freq[s[i]-'a'] != 0)
        {
            freq[s[i]-'a']--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

void solve()
{
    string s;
    cin >> s;
    string t;
    long long n = s.size();
    long long p1 = 0;
    while (p1 < n)
    {
        if (s[p1] != s[n - 1 - p1])
        {
            break;
        }
        else
            p1++;
    }
    if (p1 == n)
    {
        cout << 0 << endl;
        return;
    }
    for (long long i = p1; i < n - p1; i++)
    {
        t += s[i]; // remaining;
    }
    s = t;
    n = s.size();
    reverse(t.begin(), t.end());
    long long low = 0, high = n;
    while (low < high)
    {
        long long mid = (low + high) / 2;
        if (check(s, mid) || check(t, mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << low << endl;
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