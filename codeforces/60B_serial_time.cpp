#include <bits/stdc++.h>
using namespace std;

int count(int i, int j, int k, vector<vector<vector<char>>>& mat, vector<vector<vector<bool>>>& visited) {
    visited[k][j][i] = true;

    vector<vector<int>> direction = {
        {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0},
        {0, 0, 1}, {0, 0, -1}
    };
    
    int cn = 1;

    for (auto& dir : direction) {
        int new_i = i + dir[2];
        int new_j = j + dir[1];
        int new_k = k + dir[0];
        
        if (new_i >= 0 && new_i < mat[0][0].size() &&     
            new_j >= 0 && new_j < mat[0].size() &&          
            new_k >= 0 && new_k < mat.size() &&             
            mat[new_k][new_j][new_i] == '.' &&              
            !visited[new_k][new_j][new_i]) {                

            cn += count(new_i, new_j, new_k, mat, visited);
        }
    }
    return cn;
}

int main() {
    int k, n, m;
    cin >> k >> n >> m;
    
    vector<vector<vector<char>>> mat(k, vector<vector<char>>(n, vector<char>(m)));
    for (int layer = 0; layer < k; layer++) {
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                cin >> mat[layer][row][col];
            }
        }
    }
    
    int x, y;
    cin >> x >> y;
    x--; y--;
    
    vector<vector<vector<bool>>> visited(k, vector<vector<bool>>(n, vector<bool>(m, false)));
    
    cout << count(y, x, 0, mat, visited) << endl;

    return 0;
}
