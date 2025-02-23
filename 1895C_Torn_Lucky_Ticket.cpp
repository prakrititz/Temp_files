#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<string> a(n);
    map<pair<long long, long long>, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        cin >> a[i];
        long long sum = 0;
        for (long long j = 0; j < a[i].size(); j++)
        {
            sum += a[i][j] - '0';
        }
        mp[{a[i].size(), sum}]++;
    }
    long long sum;
    long long rem;
    long long count = 0;
    for (long long i = 0; i < n; i++)
    {
        long long len = a[i].size();
        if (a[i].size() == 1)
        {
            sum = a[i][0] - '0';
            count += mp[{1, sum}];
        }
        else if (a[i].size() == 2)
        {
            sum = a[i][0] - '0' + a[i][1] - '0';
            count += mp[{2, sum}];
        }
        else if (a[i].size() == 3)
        {

            sum = a[i][0] - '0' + a[i][1] - '0';
            rem = a[i][2] - '0';
            count += mp[{1, sum - rem}];

            // look for 3;
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0';
            count += mp[{3, sum}];

            reverse(a[i].begin(), a[i].end());
            sum = a[i][0] - '0' + a[i][1] - '0';
            rem = a[i][2] - '0';
            count += mp[{1, sum - rem}];

            // look for 3;
            // sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0';
            // count += mp[{3, sum}];

            reverse(a[i].begin(), a[i].end());
        }
        else if (a[i].size() == 4)
        {
            // look for 2
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0';
            rem = a[i][3] - '0';
            count += mp[{2, sum - rem}];

            // look for 4;
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0' + a[i][3] - '0';
            count += mp[{4, sum}];

            reverse(a[i].begin(), a[i].end());

            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0';
            rem = a[i][3] - '0';
            count += mp[{2, sum - rem}];

            // look for 4;
            // sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0' + a[i][3] - '0';
            // count += mp[{4, sum}];

            reverse(a[i].begin(), a[i].end());
        }
        else if (a[i].size() == 5)
        {

            // look for 1
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0';
            rem = a[i][4] - '0' + a[i][3] - '0';
            count += mp[{1, sum - rem}];

            // look for 3;
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0' + a[i][3] - '0';
            rem = a[i][4] - '0';
            count += mp[{3, sum - rem}];
            // 5
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0' + a[i][3] - '0' + a[i][4] - '0';
            count += mp[{5, sum}];

            reverse(a[i].begin(), a[i].end());
            // look for 1
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0';
            rem = a[i][4] - '0' + a[i][3] - '0';
            count += mp[{1, sum - rem}];

            // look for 3;
            sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0' + a[i][3] - '0';
            rem = a[i][4] - '0';
            count += mp[{3, sum - rem}];
            // 5
            // sum = a[i][0] - '0' + a[i][1] - '0' + a[i][2] - '0' + a[i][3] - '0' + a[i][4] - '0';
            // count += mp[{5, sum}];
            reverse(a[i].begin(), a[i].end());
        }
    }
    cout << count << endl;
    return 0;
}