#include <bits/stdc++.h>
#define endl '\n'
#define dbg cout<<"xxxx"<<endl;
using ll = long long;using ull = unsigned long long;using LL = long long;using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;
#define int long long
inline void Tick()
{
	int n;ll m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i = 1;i <= n;i++)cin>>a[i];
	ll l = 1,r = 1e18;
	while(l < r)
	{
		ll mid = (l + r)/2;
		int sum = 0;
		for(int i = 1;i <= n;i++)
		{
			sum+=a[i]/mid;
			if(sum>m)
			{
				break;
			}
		}
		if(sum>m)
		{
			l = mid + 1;
		}
		else 
		{
			r = mid;
		}
	}
	cout<<l<<endl;
}
/*
1
5 10
2 2 3 2 2


*/

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int NTTTT = 1;
	cin>>NTTTT;
	while (NTTTT--)Tick();
	
	return 0;
}
