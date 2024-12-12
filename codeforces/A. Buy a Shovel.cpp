#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int k, r;cin>>k>>r;

	int ans = 1;
	int temp = k % 10;
	for(int i = 1;i<=10;i++)
	{
		if((temp*i)%10 == 0 || (temp*i)%10 == r)
		{
			ans = i;
			break;
		}
	}
	cout<<ans<<endl;

	return 0;
}