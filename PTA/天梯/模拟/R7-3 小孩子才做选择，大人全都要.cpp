#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x,y;
	cin>>x>>y;
	int a = max(x,y),b = min(x,y);
	if(a>0) {
		cout<<a<<" ";
		if(a+b>0) {
			cout<<a+b<<endl;
			cout<<"^_^"<<endl;
		} else if(a+b<0) {
			cout<<0<<endl;
			cout<<"T_T"<<endl;
		} else {
			cout<<0<<endl;
			cout<<"-_-"<<endl;
		}
	} else {
		cout<<0<<" "<<0<<endl;
		cout<<"T_T"<<endl;
	}


	return 0;
}