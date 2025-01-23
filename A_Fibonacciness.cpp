#include <iostream>
#include <vector>
using namespace std;

int cal(int a1, int a2, int a4, int a5, int a3) {
    int fib = 0;
    if (a3 == a1 + a2) fib++;         
    if (a4 == a2 + a3) fib++;        
    if (a5 == a3 + a4) fib++;    
    return fib;
}

int main() {
    int t;
    cin >> t;                                
    vector<int> res;

    while (t--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;       
        int maxi = 0;

        for (int a3 = -200; a3 <= 200; ++a3) {  
            maxi = max(maxi, cal(a1, a2, a4, a5, a3));
        }

        res.push_back(maxi);   
    }
    for (int result : res) {
        cout << result << endl;            
    }

    return 0;
}
