#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long int n;
        cin >> n;
        vector<vector<long long int>> g(n); 
        vector<long long int> deg(n, 0);
        long long int temp1, temp2;
        for(long long int i = 0; i<n-1; i++){
            cin >> temp1 >> temp2;
            temp1--;
            temp2--;
            deg[temp1]++;
            deg[temp2]++;
            g[temp1].push_back(temp2);
            g[temp2].push_back(temp1);
        }
        long long int maxe = LLONG_MIN;
        long long int index;
        vector<long long int> indices;
        for(long long int i = 0; i<n; i++){
            long long int size = g[i].size();
            if(maxe < size){
                maxe = size;
                index = i;
            }
        }
        indices.push_back(index);
        for(long long int i = 0; i<n; i++){
            long long int size = g[i].size();
            if(size == maxe && i != index){
                indices.push_back(i);
                break;
            }
        }
        long long int count = 0;
        for(long long int i = 0; i<2 && i<indices.size(); i++){
            long long int temp_count = maxe;
            vector<long long int> temp_deg = deg;
            deg[indices[i]] = -1;
            for(long long int j = 0; j<g[indices[i]].size(); j++){
                deg[g[indices[i]][j]]--;
            }
            sort(deg.begin(), deg.end(), greater<>());
            temp_count += deg[0]-1;
            count = max(temp_count, count);
            deg = temp_deg;
        }
        cout << (count) << endl;
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