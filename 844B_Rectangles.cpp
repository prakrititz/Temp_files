#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc = 1;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                mat[i].push_back(x);
            }
        }

        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) row[i]++;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[j][i] == 1) col[i]++;
            }
        }

        long long count = 0; 
        for (int i = 0; i < row.size(); i++) {
            long long one = (1LL << row[i]) - 1;            
            long long zero = (1LL << (m - row[i])) - 1;    
            count += one;
            count += zero;
        }

        for (int i = 0; i < col.size(); i++) {
            if (col[i] > 1) {
                long long one = ((1LL << col[i])-1) - col[i];    
                count += one;
            }
            if (n - col[i] > 1) {
                long long zero = ((1LL << (n - col[i]))-1) - (n-col[i]); 
                count += zero;
            }
        }

        cout << count << endl;
    }
    return 0;
}
