#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
using ll = long long;

signed main()
{
	int n;
	cin>>n;
	vector<int>a(n);
	for(auto &i:a)cin>>i;
	int sum = 0;
	for(int i = 0;i < n;i++)
	{
		string x = to_string(a[i]);
		for(auto j:x)sum+=j - '0';
	}
	if(sum%3==0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
