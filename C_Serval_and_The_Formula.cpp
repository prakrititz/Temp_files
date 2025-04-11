#include <bits/stdc++.h>
using namespace std;
 
#define int int64_t
 
void solve() {
  int x, y; cin >> x >> y;
  if (x == y) {
    cout << "-1\n";
    return;
  }
  if (x < y) swap(x, y);
  int lg = __lg(x) + 1;
  int k = (1LL << lg) - x;
  assert(x + k + y + k == ((x + k) ^ (y + k)));
  cout << k << '\n';
}
 
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int T = 1;
  cin >> T;
  while (T--) solve();
  return 0;
}
