#include <bits/stdc++.h>
using namespace std;

int dist(int x, int y)
{
    if (x % 3 != 2 || y % 3 != 2)
    {
        return x + y;
    }
    return x + y + 2;
}

struct node // the set uses a const comparator 
{
    int x, y;
    bool operator<(const node &a) const
    {
        if (dist(a.x, a.y) != dist(x, y))
        {
            return dist(x, y) < dist(a.x, a.y);
        }
        if (x != a.x)
        {
            return x < a.x;
        }
        return y < a.y;
    }
};
void solve()
{
    int n;
    cin >> n;
    set<node> seat, table;
    for (int i = 1; i <= 2 * (sqrt(n)); i++)
    {
        for (int j = 1; j <=2 * (sqrt(n)); j++)
        {
            table.insert(node{(i - 1) * 3 + 1, (j - 1) * 3 + 1});
            for (int x = 0; x <= 1; x++)
                for (int y = 0; y <= 1; y++)
                    seat.insert((node){(i - 1) * 3 + x + 1, (j - 1) * 3 + y + 1});
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int p;
        cin >> p;
        if (p == 0)
        {
            node cur = *table.begin();
            table.erase(table.begin());
            cout << cur.x << ' ' << cur.y << '\n';
            seat.erase(cur); // occupy nearest occupied table
        }
        if (p == 1)
        {
            node cur = *seat.begin();
            seat.erase(*seat.begin());
            cout << cur.x << ' ' << cur.y << '\n';
            if (cur.x % 3 == 1 && cur.y % 3 == 1) // if new seat then remvoe the table too
                table.erase(cur);
        }
    }
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