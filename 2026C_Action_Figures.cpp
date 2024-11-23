#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;

        long long total = (long long)n * (n + 1) / 2;

        priority_queue<int> pq;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '1')
            {
                pq.push(i + 1);
            }
            else if (!pq.empty())
            {
                total -= pq.top();
                pq.pop();
            }
        }
        vector<int> remaining;
        while (!pq.empty())
        {
            remaining.push_back(pq.top());
            pq.pop();
        }
        reverse(remaining.begin(), remaining.end());

        int mid = remaining.size() / 2;
        for (int i = remaining.size() - 1; i >= mid; i--)
        {
            total -= remaining[i];
        }
        if (remaining.size() % 2 == 1)
        {
            total += remaining[mid];
        }
        cout << total << "\n";
    }
    return 0;
}
