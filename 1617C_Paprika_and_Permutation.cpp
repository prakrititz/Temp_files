#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        set<int> st;
        for (int i = 1; i <= n; i++) {
            st.insert(i);
        }

        vector<int> rem;
        for (int i = 0; i < n; i++) {
            int v;
            cin >> v;
            if (st.count(v)) {
                st.erase(v);
            } else {
                rem.push_back(v);
            }
        }

        sort(rem.rbegin(), rem.rend()); 
        bool err = false;

        for (int x : rem) {
            if (st.empty()) {
                err = true;
                break;
            }
            int largest = *st.rbegin();
            if (largest > (x - 1) / 2) {
                err = true;
                break;
            }
            st.erase(largest);
        }
        if(err)cout<<-1<<endl;
        else cout<<rem.size()<<endl;
    }

    return 0;
}
