#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        long long n, b, c;
        cin>>n>>b>>c;
        if(c==0 && b==0)

        {
            if(n==1)cout<<0<<endl;
            else if(n==2)cout<<1<<endl;
            else
            cout<<-1<<endl;
        }
        else{
            if(c>n-1)
            {
                cout<<n<<endl;
            }
            else{
                if(b!=0)
                {
                  long long steps = (n - 1 - c) / b;
                //   cout<<"steps "<<steps<<endl;
                  cout << (n-1 - steps) << endl;
                }
                else{
                    if(c==n-1 || c ==n-2)
                    {
                       cout<<n-1<<endl;
                    }
                    else{
                         cout<<-1<<endl;
                    }
                    
                }
            }

        }
        
    }
    return 0;
}