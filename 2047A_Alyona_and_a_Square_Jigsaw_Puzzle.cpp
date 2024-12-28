#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i = 0; i< n ;i++)cin>>a[i];
        int count = 0; 
        int sum = 0;
        for(int i =0 ; i< n ;i++)
        {
            sum+=a[i];
            int val = sqrt(sum);
            if(val * val == sum && val%2!=0)
            {
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
