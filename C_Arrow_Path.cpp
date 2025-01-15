#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& arr, vector<vector<bool>>& visited, int i, int j, int n) {
    if (i < 0 || i >= 2 || j < 0 || j >= n || visited[i][j]) {
        return;
    }
    // cout<<i<<" "<<j<<endl;
    visited[i][j] = true;
    //right
    if (j + 1 < n) {
        if(arr[i][j+1] == 1)

        {   visited[i][j+1] = true;
            // visited[i][j+2] = true;
            dfs(arr, visited, i, j + 2, n);
        }
    }
    //left
    if (j - 1 >= 0) {
        if(arr[i][j-1]==-1)
        {
            visited[i][j-1] = true;
            dfs(arr, visited, i, j-2, n);
        }
    }
    //down
    if (i == 0) {
        if(arr[1][j] == 1)
        {
            visited[1][j] = true;
            dfs(arr, visited, 1, j + 1, n);
        }
        else
        {
            visited[1][j] = true;
            dfs(arr, visited, 1, j - 1, n);
        }
    }
    //top
    if (i == 1) {
        if(arr[0][j] == 1)
        {
            visited[0][j] = true;
            dfs(arr, visited, 0, j + 1, n);
        }
        else
        {
            visited[0][j] = true;
            dfs(arr, visited, 0, j - 1, n);
        }
    }
    return;
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        vector<vector<int>> arr(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            arr[0][i] = (s1[i] == '>') ? 1 : -1;
            arr[1][i] = (s2[i] == '>') ? 1 : -1;
        }
        vector<vector<bool>> visited(2, vector<bool>(n, false));
        dfs(arr, visited, 0, 0, n);
        if (visited[1][n - 1]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
