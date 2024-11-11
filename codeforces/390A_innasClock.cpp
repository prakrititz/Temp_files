#include<bits/stdc++.h>
using namespace std;
int main()
{
        int  n;
        cin>>n;
        vector<pair<int, int> >pos(n);
        vector<int>mpx(101, 0);
        vector<int>mpy(101, 0);
        for(int i = 0 ;i< n; i++)
        {
            int x, y; cin>>x>>y;
            mpx[x]++;
            mpy[y]++;
        }
        int countx = 0;
        int county = 0;
        for(int i =0 ;i<= 100; i++)
        {
            if(mpx[i]!=0)countx++;
        }
        for(int i = 0; i<= 100 ;i++)
        {
            if(mpy[i]!=0)county++;
        }
        cout<<min(countx, county)<<endl;

}