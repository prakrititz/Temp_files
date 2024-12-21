#include<bits/stdc++.h>
using namespace std;
void find_req(long long &currentvalue , long long &to_find, long long &left, long long &right, vector<long long>&arr)
{
    if(currentvalue==arr.size())
    {
        arr[left] = currentvalue;
        return;
    }
    long long current_size = right-left+1;
    long long val = pow(2,current_size-2);
    if(to_find <= val)
    {
        arr[left]= currentvalue;
        left++;
        currentvalue++;
        find_req(currentvalue, to_find, left, right, arr);
    }
    else{
        arr[right] = currentvalue;
        right--;
        currentvalue++;
        to_find -= val;
        find_req(currentvalue, to_find, left, right,arr);
    }
}
int main()
{
    long long tc;
    cin>>tc;
    while(tc--)
    {
        long long n, k;
        cin>>n>>k;
        vector<long long>a(n);
        if (n <= 60 && (1ll << (n - 1)) < k) {
            cout << -1 << endl;
        }
        else{
        long long current_value = 1;
        long long left = 0; long long right = n-1;
        find_req(current_value, k, left, right, a);
        for(int i = 0; i< a.size(); i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        }
        
    }
    return 0;
}