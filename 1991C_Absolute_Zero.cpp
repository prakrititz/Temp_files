#include<bits/stdc++.h>
using namespace std;
int main() {
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<long long>a(n);
        for(int i = 0; i< n ;i++)cin>>a[i];
        bool has_even = false;
        bool has_odd = false;
        for(int i =0; i<n ; i++)
        {
            if(a[i]%2==0)has_even = true;
            else has_odd = true;
        }
        if(has_even && has_odd){
            cout<<-1<<endl;
        }
        else{
            vector<long long> operations;
        while (true) {
            set<long long> uniqueValues(a.begin(), a.end());

            if (uniqueValues.size() == 1 && *uniqueValues.begin() == 0) {
                break;
            }

            long long minValue = *uniqueValues.begin();
            long long maxValue = *uniqueValues.rbegin();
            long long x = (minValue + maxValue) / 2;
            operations.push_back(x);

            for (int i = 0; i < n; i++) {
                a[i] = abs(a[i] - x);
            }
        }
        cout << operations.size() << "\n";
        for (long long op : operations) {
            cout << op << " ";
        }
        cout << "\n";
        }
    }
    return 0;
}
