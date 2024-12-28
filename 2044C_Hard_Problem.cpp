#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin>>tc;
    while(tc--)
    {
        int m, a, b, c;
        cin>>m>>a>>b>>c;
        int tp  = min(a, m);
        int bt = min(b, m);
        int tp_left = max(0, m-a);
        int bt_left = max(0, m-b);
        int cu = min(tp_left + bt_left, c);
        cout<<tp+bt+cu<<endl;
    }
    return 0;
}