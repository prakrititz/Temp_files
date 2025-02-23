#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;
long long mult(long long x, long long y)
{
    return (x * y) % MOD;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> twos_before(n + 1, 0);
    // first i wil count the number of twos before;
    for (int i = 0; i < n; i++)
    {
        twos_before[i + 1] = twos_before[i];
        if (arr[i] == 2)
            twos_before[i + 1]++;
    }
    vector<long long> pow2(n + 1, 1); // i will precompute the power;
    vector<long long> inv(n + 1, 1);  // i will precompute the inverse power;
    long long half = (MOD + 1) / 2;
    for (int i = 1; i <= n; i++)
    {
        pow2[i] = mult(pow2[i - 1], 2);
        inv[i] = mult(inv[i - 1], half);
    }
    // any valid beautiful starts with 1 and then ends with 3 rest all should be 2,
    long long sum_of_ones = 0;
    long long count_of_ones = 0; // this is basically no of ones encounterd so far
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1) // this means i can start a beautiful array here
        {
            sum_of_ones = (sum_of_ones + inv[twos_before[i + 1]]) % MOD;
            // this will like the sum of inverses powers like when thre is 1 i can start there so i will divide total no of twos by total nos encountered so far; this is basically like a gp;
            count_of_ones++;
        }
        else if (arr[i] == 3)
        {
            long long combinations = mult(pow2[twos_before[i]], sum_of_ones); // no i will multiply no of twos before 3 with no of twos before it with the sum ;
            combinations = (combinations - count_of_ones) % MOD;              // this is to substract the values where no 2twos were taken
            result = (result + combinations) % MOD;                           // add the sequence that ends with this particular three
        }
    }

    cout << result << "\n";
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