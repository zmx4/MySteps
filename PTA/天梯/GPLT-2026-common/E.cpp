#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
	
	int a,b;
	cin >> a >> b;
	int tar = a + b;
	int now = 1;
	int x;
	bool flag = 0;
	int cnt = 0;
	while(cin >> x)
	{
		if(x == a + b)
		{
			printf("%lld Accepted %02lld:%02lld:%02lld",tar,now / 3600,now  % 3600 / 60,now % 60);
			flag = 1;
			break;
		}
		now += 2;
		cnt ++;
		if(cnt > 5400)break;
	}
	if(!flag)printf("%2lld Wrong Answer %02lld:%02lld:%02lld",x,now / 3600,now  % 3600 / 60,now % 60);
}
