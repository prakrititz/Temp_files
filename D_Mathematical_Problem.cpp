#include <bits/stdc++.h>
using namespace std;
vector<long long> pre11, pre7, pre9;

void solve()
{
    long long n;
    cin >> n;
    // for (int i = 0; i < pre11.size(); i++)
    //     cout << pre11[i] << endl;
    // return;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 3)
    {
        cout << 169 << endl
             << 196 << endl
             << 961 << endl;
    }
    else if (n == 5)
    {
        cout << 16384 << endl
             << 31684 << endl
             << 36481 << endl
             << 38416 << endl
             << 43681 << endl;
    }
    else if (n == 7)
    {
        for (long long i = 0; i < 7; i++)
        {
            cout << pre7[i] << endl;
        }
    }
    else if (n == 9)
    {
        for (long long i = 0; i < 9; i++)
        {
            cout << pre9[i] << endl;
        }
    }
    else
    {
        for (long long i = 0; i < n; i++)
        {
            cout << pre11[i];
            for (long long j = 11; j < n; j++)
                cout << 0;
            cout << endl;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (long long i = 0; i * i < 1e11; i++)
    {
        if (i * i >= 1e10)
        {
            long long val = i * i;
            string ans = to_string(val);
            sort(ans.begin(), ans.end());
            if (ans == "00123456789")
            {
                pre11.push_back(i * i);
            }
        }
    }
    for (long long i = 0; i * i < 1e7; i++)
    {
        if (i * i >= 1e6)
        {
            long long val = i * i;
            string ans = to_string(val);
            sort(ans.begin(), ans.end());
            if (ans == "0000169")
            {
                pre7.push_back(i * i);
            }
        }
    }

    for (long long i = 0; i * i < 1e9; i++)
    {
        if (i * i >= 1e8)
        {
            long long val = i * i;
            string ans = to_string(val);
            sort(ans.begin(), ans.end());
            if (ans == "123456789")
            {
                pre9.push_back(i * i);
            }
        }
    }
    // cout << pre11.size() << endl;
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}