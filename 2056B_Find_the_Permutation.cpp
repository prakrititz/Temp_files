#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> graph(n);
        for(int i = 0; i < n; i++) {
            cin >> graph[i];
        }
        vector<int> perm(n);
        for(int i = 0; i < n; i++) {
            perm[i] = i;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n-1; j++) {
                int v1 = perm[j], v2 = perm[j+1];
                if(v1 < v2) {
                    if(graph[v1][v2] == '0') {
                        swap(perm[j], perm[j+1]);
                    }
                } else {
                    if(graph[v2][v1] == '1') {
                        swap(perm[j], perm[j+1]);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            cout << perm[i] + 1;
            if(i < n-1) cout << " ";
        }
        cout << "\n";
    }
    
    return 0;
}