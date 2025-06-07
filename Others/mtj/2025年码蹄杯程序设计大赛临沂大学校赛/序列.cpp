#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
using ll = long long;

signed main()
{
	int n,m;
	cin>>n>>m;
	vector<int>a;
	int sum = 0;
	for(int i = 1;i <= n&&sum < n ;i++)
	{
		a.push_back(i);
		sum += i;
	}
//	for(auto i:a)cout<<i<<endl;
	//cout<<a.size()<<endl;
	if(m>a.size())cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
