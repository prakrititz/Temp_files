#include<bits/stdc++.h>
using namespace std;
#define int long long 
int maxSubarrySum(vector<int>&a)
{
    int n = a.size();
    int maxSum = LONG_LONG_MIN;
    int currsum = 0;
    //idea is if sum becomes negative no need to take that segment
    //this is because element can be negative 
    // to print the array;
    for(auto it:a)
    {
        currsum += it;
        if(currsum<0)
        {
            currsum = 0;
        }
        maxSum = max(currsum, maxSum);
    }
    if (*max_element(a.begin(), a.end()) < 0) return *max_element(a.begin(), a.end()); // need this line for all negative elements other wise it outputs 0 whjich is incorrect
    return maxSum;
}

int version2(vector<int>&a)
{
    int n = a.size();
    int maxSum = a[0];
    int currsum = a[0];
    //idea is if sum becomes negative no need to take that segment
    //this is because element can be negative 
    for(int i = 1;i<n;i++)
    {
        currsum  = max(a[i], currsum+a[i]);
        maxSum = max(currsum, maxSum);
    }
    return maxSum;
}

void maxSubarrySumPrintsTOO(vector<int>&a)
{
    int n = a.size();
    int maxSum = LONG_LONG_MIN;
    int currsum = 0;
    //idea is if sum becomes negative no need to take that segment
    //this is because element can be negative 
    // to print the array;
    int start = 0;
    int end = 0;
    for(int i = 0;i<n; i++)
    {
        currsum += a[i];
        end ++;
        if(currsum<0)
        {
            currsum = 0;
            start = i;
        }
        maxSum = max(currsum, maxSum);
    }
    if (*max_element(a.begin(), a.end()) < 0) {
        cout<< max_element(a.begin(), a.end())-a.begin();
        return;
    } // index of largest negative number
    for(int i = start;i<=end;i++)cout<<a[i]<<" ";
    cout<<endl;
}



void solve()
{   
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i = 0;i<n; i++)cin>>a[i];
    cout<<maxSubarrySum(a)<<endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    while(tc--)
    {
        solve();
    }
    return 0;
}