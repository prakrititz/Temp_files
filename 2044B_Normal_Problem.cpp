#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--)
    {
        string s;
        cin>>s;
        reverse(s.begin(), s.end());
        for(int i =0 ; i< s.size(); i++)
        {
            if(s[i]=='p'){
                s[i]='q';
            }
            else if(s[i]=='q')s[i]='p';
        }
        cout<<s<<endl;

    }
    return 0;
}