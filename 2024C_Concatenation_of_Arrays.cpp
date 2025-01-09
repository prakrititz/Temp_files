#include<bits/stdc++.h>
using namespace std;

// Custom comparator
bool comp(pair<int,int>& a, pair<int,int>& b) {
    int maxa = max(a.first, a.second);
    int maxb = max(b.first, b.second);
    if(maxa != maxb) {
        return maxa < maxb;
    }
    int mina = min(a.first, a.second);
    int minb = min(b.first, b.second);
    return mina < minb;
}

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), comp);
        for(int i = 0; i < n; i++) {
            cout << a[i].first << " " << a[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}