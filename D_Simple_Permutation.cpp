#include <bits/stdc++.h>
using namespace std;

vector<int> primes;

void sieve(int n)
{
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 2; i <= n; ++i)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
        }
    }
}

int next(int p0)
{
    int p = max(p0, 2);
    auto it = lower_bound(primes.begin(), primes.end(), p);
    return *it;
}

vector<int> prr(int n, int P, int L)
{
    set<int> ss;
    for (int i = 1; i <= n; ++i)
    {
        ss.insert(i);
    }
    vector<int> perm;
    long long s = 0;
    for (int i = 1; i <= min(L, n); ++i)
    {
        long long lb = (P - 1LL) * i - s;
        long long ub = P * i - s;
        auto it = ss.upper_bound(lb);
        if (it == ss.end() || *it > ub)
        {
            it = ss.begin();
        }
        int p_i = *it;
        ss.erase(it);
        perm.push_back(p_i);
        s += p_i;
    }
    for (int num : ss)
    {
        perm.push_back(num);
    }
    return perm;
}

void solve()
{
    int n;
    cin >> n;
    int R = n / 3 - 1;
    int L_target = max(R, 1);
    double P0 = (L_target + 2) / 2;
    int P = next(ceil(P0));
    int L = 2 * P - 1;
    vector<int> perm;
    if (L > n)
    {
        perm.push_back(2);
        perm.push_back(1);
        for (int i = 3; i <= n; ++i)
        {
            perm.push_back(i);
        }
    }
    else
    {
        perm = prr(n, P, L);
    }
    for (int i = 0; i < perm.size(); ++i)
    {
        cout << perm[i];
        if (i < perm.size() - 1)
            cout << " ";
    }
    cout << endl;
}

int main()
{
    sieve(50000);
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
