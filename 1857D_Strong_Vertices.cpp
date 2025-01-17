 #include <bits/stdc++.h>
 using namespace std;
 
 void solve() {
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for (int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++) {
        cin>>b[i];
    }
    vector<pair<int,int>>ind;
    for (int i = 0; i < n; i++) {
        ind.push_back(make_pair(a[i]-b[i], i+1));
    }
    sort(ind.rbegin(), ind.rend());
    int max = ind[0].first;
    int i = 0;
    vector<int>ans;
    while(ind[i].first==max)
    {
        ans.push_back(ind[i].second);
        i++;
    }
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int i =0; i<ans.size(); i++)cout<<ans[i]<<" ";
    cout<<endl;
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