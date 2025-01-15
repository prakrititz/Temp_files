#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    long long half = n / 2;

    if (half % 2 == 0) {
        cout << half / 2 - 1 << endl; 
    } else {
        cout << half / 2 << endl;
    }

    return 0;
}
