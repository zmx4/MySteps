#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n,k;cin>>n>>k;

	int time=240-k;

	for(int i=1;i<=n;++i)
	{
		time-=5*i;
		if(time<0)
		{
			cout<<i-1<<endl;
			return 0;
		}
	}
	cout<<n<<endl;
	return 0;
}