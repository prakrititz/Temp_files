#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<pair<int, int>>v;
    vector<pair<int, int>>X;
    vector<pair<int , int>>Y;
    for(int i = 0;i<n; i ++)
    {
        int x, y;
        cin>>x>>y;
        v.push_back({x, y});
        X.push_back({x, i});
        Y.push_back({y, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    set<int>a, b;
    set<int>c, d;
    for(int i = 0;i<n/2;i++){
        a.insert(X[i].second);
        c.insert(Y[i].second);
        b.insert(X[n-1-i].second);
        d.insert(Y[n-1-i].second);
    }
    auto get_intersection = [&](set<int>&a, set<int>b)
    {
        set<int>res;
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(res, res.begin()));
        return res;
    };
    set<int> a1 = get_intersection(a, c); 
    set<int> a2 = get_intersection(b, d); 
    set<int> a3 = get_intersection(a, d);  
    set<int> a4 = get_intersection(c, b); 
    vector<int>b1(a1.begin(), a1.end());
    vector<int>b2(a2.begin(), a2.end());
    vector<int>b3(a3.begin(), a3.end());
    vector<int>b4(a4.begin(), a4.end());
    for(int i = 0;i<min(b1.size(), b2.size());i++)
    {
        cout<<b1[i]+1<<" "<<b2[i]+1<<endl;
    }
    for(int i = 0;i<min(b3.size(), b4.size());i++)
    {
        cout<<b3[i]+1<<" "<<b4[i]+1<<endl;
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