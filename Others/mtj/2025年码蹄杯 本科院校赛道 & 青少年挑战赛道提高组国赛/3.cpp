#include <bits/stdc++.h>
#define endl '\n'
using ll = long long;using ull = unsigned long long;using LL = long long;using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

inline void Tick()
{
	int n,m;cin>>n>>m;
	vector<int>a(n+3);
	for(int i = 1;i <= n;i++)cin>>a[i];
	set<int>st;
	for(int i = 1;i <= n;i++)
	{
		st.insert(a[i]);
	}
	int k = 0;
	while(k < m - 1&&!st.empty())
	{
		st.erase(st.begin());
		k++;
	}
	if(!st.empty())cout<<*st.begin()<<endl;
	else cout<<-1<<endl;
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
