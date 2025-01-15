#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
	cin>>n;
	vector<int> a(n),c(n);
	for(int i = 0;i <n ;i++) cin>>a[i];
	vector<pair<int, int>>b;
	for(int i = 0;i <n ;i++){
		cin>>x;
		b.push_back({x,i});
	}
	sort(a.rbegin(), a.rend());
	sort(b.begin(), b.end());
	for(int i = 0;i <n ;i++) c[b[i].second]=i;
	for(int i = 0;i <n ;i++) cout<<a[c[i]]<<' ';
    return 0;
}