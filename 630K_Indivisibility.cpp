#include <iostream>

using namespace std;
int main() {
    long long n;
    cin >> n;
    long long result = n;
    result -= n / 2;// 2
    result -= n / 3;// 3
    result -= n / 5;// 5
    result -= n / 7;// 7
    result += n / 6; // 2*3
    result += n / 10;// 2*5
    result += n / 14;// 2*7
    result += n / 15;// 3*5
    result += n / 21;// 3*7
    result += n / 35;// 5*7
    result -= n / 30; // 2*3*5
    result -= n / 42; // 2*3*7
    result -= n / 70; // 2*5*7
    result -= n / 105;// 3*5*7
    result += n / 210;// 2*3*5*7
    cout<<result<<endl;
    return 0;
}