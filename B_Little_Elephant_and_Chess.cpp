 #include <bits/stdc++.h>
 using namespace std;
 
 int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    vector<string>s(8);
    for(int i =0; i<8 ;i++)
    {
        cin>>s[i];
    }
    for(int i =0 ; i<8; i++)
    {
        for(int j = 0; j<7;j++)
        {
            if(s[i][j]==s[i][j+1])
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        if(s[i][0]==s[i][7])
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
 }