#include<bits/stdc++.h>
using namespace std;

struct node{
	int x,y;
	bool operator< (node b)const{
		return x + y < b.x+b.y;
	}
};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	
	int n;cin >> n;
	vector<node> a;
	set<node> st;
	for(int i = 0;i < n;++i)
	{
		node nd;cin >> nd.x >> nd.y;
		if(!st.count(nd))
		{
			a.push_back(nd);
		}
	}
	vector<int> cost(n+1,INT_MAX);
	int m = a.size();
	for(int i = 0;i < m;++i)
	{
		int x = a[i].x;
		int y = a[i].y;
		int xxx = 0;
		for(int j = 0;j < m;++j)
		{
			if(i == j)continue;
			xxx = max(xxx,abs(x - a[j].x) + abs(y - a[j].y));
		}
		cost[i]=xxx;
	}
	int ans = INT_MAX;
	for(int i = 0;i < m;++i)
	{
		ans = min(cost[i],ans);
	}
	cout << ans << endl;
	return 0;
}
