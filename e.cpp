#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, k;
        cin >> n >> k;
        
        vector<pair<long long, int>> events;
        for(int i = 0; i < n; i++) {
            long long a;
            cin >> a;
            events.push_back({a, 1});
        }
        for(int i = 0; i < n; i++) {
            long long b;
            cin >> b;
            events.push_back({b, 2});
        }
        sort(events.begin(), events.end(), 
             [](const pair<long long, int>& a, const pair<long long, int>& b) {
                 return a.first < b.first || (a.first == b.first && a.second > b.second);
             });
        
        long long max_revenue = 0;
        int pos = n;
        int neg = 0;
        
        for(int i = 0; i < events.size(); i++) {
            long long price = events[i].first;
            
            if(neg <= k) {
                long long current_revenue = price * (pos + neg);
                max_revenue = max(max_revenue, current_revenue);
            }
            
            while(i < events.size() && events[i].first == price) {
                if(events[i].second == 1) {
                    pos--;
                    neg++;
                } else {
                    neg--;
                }
                i++;
            }
            i--;
        }
        
        cout << max_revenue << "\n";
    }
    return 0;
}
