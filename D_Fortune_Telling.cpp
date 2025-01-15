#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> petals(n);
    int totalSum = 0;
    int smallestOdd = 101; 

    for (int i = 0; i < n; i++) {
        cin >> petals[i];
        totalSum += petals[i];
        if (petals[i] % 2 != 0) {
            smallestOdd = min(smallestOdd, petals[i]);
        }
    }

    if (totalSum % 2 != 0) {
        cout << totalSum << endl;
    } 
    else if (smallestOdd != 101) {
        cout << totalSum - smallestOdd << endl;
    } 
    else {
        cout << 0 << endl;
    }

    return 0;
}
