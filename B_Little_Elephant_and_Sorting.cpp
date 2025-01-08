#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &x:a){
        cin>>x;
    }
    long long total =0; 
    for(int i=1 ;i< n ; i++)
    {
        if(a[i]< a[i-1])total+= a[i-1]-a[i];
    }
    cout<<total;

}