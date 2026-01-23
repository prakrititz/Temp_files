#include<bits/stdc++.h>
using namespace std;
#define int long long 
void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int>l1(n), l2(n), r1(n), r2(n);
    for(int i = 0; i < n; i++) {
        l1[i] = l2[i] = -1;
        r1[i] = r2[i] = n;
    }
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] <= a[i]) st.pop();
        if(!st.empty()) r1[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = n-1; i >= 0; i--) {
        while(!st.empty() && a[st.top()] >= a[i]) st.pop();
        if(!st.empty()) r2[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] < a[i]) st.pop();
        if(!st.empty()) l1[i] = st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i = 0; i < n; i++) {
        while(!st.empty() && a[st.top()] > a[i]) st.pop();
        if(!st.empty()) l2[i] = st.top();
        st.push(i);
    }
    int sumMax = 0, sumMin = 0;
    for(int i = 0; i < n; i++) {
        sumMax += a[i] * (i - l1[i]) * (r1[i] - i);
        sumMin += a[i] * (i - l2[i]) * (r2[i] - i);
    }

    cout << sumMax - sumMin << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc = 1;
    // cin>>tc;
    while(tc--)
    {
        solve();
    }
    return 0;
}