#include<bits/stdc++.h>
using namespace std;

int findNearestSquare(int n) {
    int sqrtN = static_cast<int>(sqrt(n));
    if (sqrtN * sqrtN == n) {
        return n; 
    }
    return (sqrtN + 1) * (sqrtN + 1);
}

void find(int &current, vector<int>&arr) {
    if (current <= 0) return;
    int nearestSquare = findNearestSquare(current);
    int x = nearestSquare - current;
    for (int i = x; i <= current; i++) {
        arr[i] = current - (i-x);
    }
    x--;
    find(x, arr);
}

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int current = n - 1;
        find(current, a);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
