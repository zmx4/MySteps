#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+10;
bool vis[N];
struct p{
	int cost,pr;
	string id;
	int age;
};
bool cmp(p a,p b)
{
	if(a.pr == b.pr)
	{
		
	}
	return a.pr > b.pr;
}
signed main()
{
	cin.tie(0);	
	ios::sync_with_stdio(0);
	int n;cin >> n;
	vector<p> v;
	for(int i = 1;i <= n;i++)
	{
		int a,b;string c;int d;
		cin >> a >> b >> c >> d;
		v.emplace_back(a,b,c,d);
	}
	for(int i = 1;i <= n;++i)
	{
		
	}
	return 0;
}
