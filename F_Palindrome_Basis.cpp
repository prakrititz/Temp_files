#include <bits/stdc++.h>
using namespace std;

const int MAX = 40004;
const int MOD = 1e9 + 7;
vector<int> palindrome;

int count(int amount, int ind, vector<vector<int>> &dp)
{
    if (amount == 0) return 1;
    if (ind < 0 || amount < 0) return 0;
    if (dp[ind][amount] != -1)
        return dp[ind][amount];
    int taken = 0;
    if (amount >= palindrome[ind])
    {
        taken = count(amount - palindrome[ind], ind, dp) % MOD;
    }
    int not_taken = count(amount, ind - 1, dp) % MOD;
    return dp[ind][amount] = (taken + not_taken) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(palindrome.size(), vector<int>(n + 1, -1));
    int ans = count(n, palindrome.size() - 1, dp);
    cout << ans << endl;
}

bool isPalindrom(int n)
{
    int t = 0, temp = n;
    while (n > 0)
    {
        t = t * 10 + n % 10;
        n /= 10;
    }
    return temp == t;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < MAX; i++)
    {
        if (isPalindrom(i))
        {
            palindrome.push_back(i);
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}
