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
        if(n%2==0)
        {
            vector<int>ans(n);int count = 1;
            for(int i = 0; i<n-1; i+=2)
            {
                ans[i] = count;
                ans[i+1] = count;count++;
            }
            for(int i = 0; i<n ;i ++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else
        {
            if(n<27)
            {
                cout<<-1<<endl;
            }
            else{
                vector<int>ans(n);
                ans[0] = 1;
                ans[9] = 1;ans[25] = 1;
                ans[10] = 2;
                ans[26] = 2;
                int count = 3;
                for(int i = 1; i<8 ;i+=2){
                    ans[i]= count;
                    ans[i+1] = count; count++;
                }
                for(int i  = 11 ;i<24; i+=2){
                    ans[i] = count;ans[i+1]= count;
                    count++;
                }
                for(int i = 27;i<n-1; i+=2)
                {
                    ans[i] = count;ans[i+1]= count;
                    count++;
                }   
                    for(int i = 0; i<n ;i++)cout<<ans[i]<<" ";
                    cout<<endl;
            }

        }
    }
    
}