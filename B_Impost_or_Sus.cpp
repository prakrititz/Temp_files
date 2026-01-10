#include <bits/stdc++.h>
using namespace std;
#define int long long
using namespace std;

void solve() {
int n;
long long m;
if (!(cin >> n >> m)) return;

vector<Elf> elves(n);
for (int i = 0; i < n; ++i) {
elves[i].id = i + 1;
cin >> elves[i].a;
}

sort(elves.begin(), elves.end(), [](const Elf& x, const Elf& y) {
return x.a < y.a;
});

if (m == 0) {
long long sum_others = 0;
for (int i = 0; i < n - 1; ++i) sum_others += elves[i].a;

if (sum_others < elves[n - 1].a) {
cout << -1 << "\n";
return;
}

vector<pair<int, int>> ops;
vector<int> fodder;
for (int i = 0; i < n - 2; ++i) fodder.push_back(i);

long long current_sum = sum_others;
long long tank_hp = elves[n - 1].a;
int idx = 0;

while (idx + 1 < fodder.size() && current_sum >= tank_hp) {
ops.push_back({elves[fodder[idx]].id, elves[fodder[idx+1]].id});
current_sum -= elves[fodder[idx]].a;
idx++;
}

for (int i = idx; i < n - 2; ++i) {
ops.push_back({elves[i].id, elves[n - 1].id});
}

ops.push_back({elves[n - 2].id, elves[n - 1].id});

cout << ops.size() << "\n";
for (auto& p : ops) cout << p.first << " " << p.second << "\n";

} else {
if (n < 2 * m) {
cout << -1 << "\n";
return;
}

vector<pair<int, int>> ops;

for (int i = 0; i < m - 1; ++i) {
ops.push_back({elves[2 * i + 1].id, elves[2 * i].id});
}

for (int i = 2 * (m - 1); i < n - 1; ++i) {
ops.push_back({elves[i + 1].id, elves[i].id});
}

cout << ops.size() << "\n";
for (auto& p : ops) cout << p.first << " " << p.second << "\n";
}
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int t;
if (cin >> t) {
while (t--) solve();
}
return 0;
}