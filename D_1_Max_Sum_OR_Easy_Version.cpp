#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            a[i] = i;
        }
        vector<int> x(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            if (x[i] == 1)
                continue;
            if (a[i] == 1)
            {
                if (i != 0)
                    swap(a[i], a[0]);
                break;
            }
            int b = a[i];
            int c = log2(b) + 1;
            int z = (1 << c) - 1;
            int idx = z ^ a[i];
            if (idx >= 0 && idx < n)
            {
                swap(a[i], a[idx]);
                x[a[i]] = 1;
                x[idx] = 1;
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; i++)
            sum += (a[i] | i);

        cout << sum << endl;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
}
