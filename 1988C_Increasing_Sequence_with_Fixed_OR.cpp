#include <bits/stdc++.h>
using namespace std;

string tobin_string(long long n)
{
    if (n == 0)
        return "0"; // Handle zero case
    string s = "";
    while (n > 0)
    {
        if (n % 2 == 0)
            s += "0";
        else
            s += "1";
        n = n / 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

long long binToint(string n)
{
    long long val = 0;
    long long power = 1; // Use power of 2 directly

    for (int i = n.size() - 1; i >= 0; i--)
    {
        if (n[i] == '1')
        {
            val += power;
        }
        power *= 2;
    }
    return val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> result;
        result.push_back(n);

        string s = tobin_string(n);
        int i = s.size() - 1;
        while (i >= 0)
        {
            if (s[i] == '1')
            {
                s[i] = '0';
                long long ans = binToint(s);
                if (ans > 0)
                    result.push_back(ans);
                s[i] = '1';
            }
            i--;
        }

        cout << result.size() << endl;
        for (int i = 0; i < result.size(); i++)
            cout << result[result.size() - 1 - i] << " ";
        cout << endl;
    }
    return 0;
}