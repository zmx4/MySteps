#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int y,w;
	cin>>y>>w;
	int maxm=max(y,w);
	int ans=6-maxm+1;
	if(ans==6)
	{
		cout<<"1/1"<<endl;
	}
	else if(ans==3)
	{
		cout<<"1/2"<<endl;
	}
	else if(ans==2)
	{
		cout<<"1/3"<<endl;
	}
	else if(ans==1)
	{
		cout<<"1/6"<<endl;
	}
	else if(ans==4)
	{
		cout<<"2/3"<<endl;
	}
	else
	{
		cout<<"5/6"<<endl;
	}

	return 0;
}