#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n), odd, even;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2) odd.push_back(a[i]);
        else even.push_back(a[i]);
    }

    // Case 1: no odd coins
    if (odd.empty()) {
        for (int i = 0; i < n; i++) cout << 0 << " ";
        cout << endl;
        return;
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int m = even.size();
    vector<long long> pref(m + 1, 0);
    for (int i = 0; i < m; i++)
        pref[i + 1] = pref[i] + even[i];

    long long oc = odd[0];
    vector<long long> ans(n);
    if(even.size()==0)
    {
        for(int i = 0;i<n;i++){
            if(i%2==0)cout<<oc<<" ";
            else cout<<0<<" ";
        }
        cout<<endl;
        return;
    }
    for (int k = 1; k <= min(n, m + 1); k++) {
        ans[k - 1] = oc + pref[k - 1];
        if(ans[k-1]%2==0)ans[k-1] = 0;
    }

    long long full_sum = oc + pref[m];
    long long smallest_even = (m ? even.back() : 0);

    for (int k = m + 2; k <= n; k++) {
        int extra = k - (m + 1);
        if (extra % 2 == 1)
            ans[k - 1] = full_sum - smallest_even;
        else
            ans[k - 1] = full_sum;
        if(ans[k-1]%2==0)ans[k-1] = 0;
    }

    if (odd.size() % 2 == 0)
        ans[n - 1] = 0;

    for (auto x : ans) cout << x << " ";
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
