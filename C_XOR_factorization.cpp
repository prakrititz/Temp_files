#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve()
{   
    int n, k;
    cin >> n >> k;
    if (k % 2) {
        for (int i = 0; i < k; i++)
            cout << n << " ";
        cout <<endl;
        return;
    }
    vector<int> a(k, n);
    if (k % 2 == 0) {
      int ptr = 0;
      for (int bit = 29; bit >= 0; bit--) {
        if (n & (1 << bit)) {
          if (ptr < k) {
            a[ptr++] ^= 1 << bit;
          } else {
            a[0] ^= 1 << bit;
          }
        } else {
          for (int i = 0; i + 1 < ptr; i += 2) {
            a[i] ^= 1 << bit;
            a[i + 1] ^= 1 << bit;
          }
        }
      }
    }
    for (int i = 0; i < k; i++) {
      cout << a[i] << " ";
    }
    cout<<endl;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}