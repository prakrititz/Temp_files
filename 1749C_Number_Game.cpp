#include <bits/stdc++.h>
using namespace std;

void solve() {
       int n;
       cin>>n;
       vector<int>v(n);
       
       for ( int i = 0; i <  n; i++)
       {
         cin>>v[i];
       }
       
        sort(v.begin(),v.end());
        int ans=0;
        for(int k=n;k>=0;k--){

            int k1=k;
            vector<int>res=v;
            int lo=0;
            int hi=n-1;
            int step=1;
            while(hi>=lo){
                int req=k1+1-step;
                while(res[hi]>req){
                    hi--;
                }

                if(step>=k){
                    ans=k;
                }

                if(hi<0 || hi<lo){
                    break;
                }

              if(res[hi]<=req){
                  hi--;
                res[lo]+=req;
                lo++;
                step++;
              }




            }

            if(step>=k+1){
                ans=max(ans,k);
                break;
            }
        }

        cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}   