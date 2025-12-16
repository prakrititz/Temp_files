#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    int x = 0;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            int y = (i + j) % n;
            if (y == 0) y = n;
            cout<<j<<" "<<y<<endl;
            cin>>x;
            if(x)
            {
                return;
            }
            cout.flush();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}