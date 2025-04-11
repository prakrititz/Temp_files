#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, h;
    cin >> n >> m >> h;

    vector<vector<int>> arr(n, vector<int>(m));

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Sort each participant's solving times
    for (long long i = 0; i < n; i++)
    {
        sort(arr[i].begin(), arr[i].end());
    }

    long long player_point = 0, player_penalty = 0, pos = 1;

    for (long long i = 0; i < n; i++)
    {
        long long penalty = 0, point = 0, cummulative_penalty = 0;
        long long currTime = 0;
        for (long long j = 0; j < m; j++)
        {
            if (arr[i][j] + currTime <= h)
            {
                point++;
                penalty = arr[i][j] + currTime;
                cummulative_penalty += penalty;
                currTime += arr[i][j];
            }
            else
            {
                break;
            }
        }
        if (i == 0)
        {
            player_point = point;
            player_penalty = cummulative_penalty;
        }
        else
        {
            if ((point > player_point) || (point == player_point && cummulative_penalty < player_penalty))
            {
                pos++;
            }
        }
    }
    cout << pos << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
