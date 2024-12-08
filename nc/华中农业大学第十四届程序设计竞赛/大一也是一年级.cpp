#include <bits/stdc++.h>
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n;cin>>n;
	while(n--)
	{
		int a,b;cin>>a>>b;
		if(a>b)cout<<">"<<endl;
		else if(a<b)cout<<"<"<<endl;
		else cout<<"="<<endl;
	}

	return 0;
}