#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string a, v;
    cin >> a >> v;
    sort(a.begin(), a.end());
    sort(v.begin(), v.end());
    int i = 0, j = 0; 
    while (i < n && j < n) {
        if (v[j] >= a[i]) {
            i++;
        }
        j++;
    }
    cout << n - i << endl;

    i = 0; j = 0; 
    while (i < n && j < n) {
        if (v[j] > a[i]) {
            i++; 
        }
        j++; 
    }
    cout << i << endl;

    return 0;
}
