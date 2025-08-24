#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;using ull = unsigned long long;using LL = long long;using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

inline void Tick()
{
	int n,m;cin>>n>>m;
	vector<int>a(n+1);
	for(int i = 1;i <= n;i++)cin>>a[i];
	while(m--)
	{
		int op,id,v;
		cin>>op>>id>>v;
		if(op==1)
		{
			a[id]+=v;
		}
		else
		{
			a[id]-=v;
		}
	}
	for(int  i= 1;i <= n;i++)cout<<a[i]<<" ";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int NTTTT = 1;
//	cin>>NTTTT;
	while (NTTTT--)Tick();

	return 0;
}
