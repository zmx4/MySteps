#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	
//	unordered_map<int,set<pair<int,int>>> mp;
	map<tuple<int,int,int>, vector<int>> id;
	vector<int> a;
	bool flag = 0;
//	for(auto &x : a)cin >> x;
	int gg;
	while (cin >> gg)
	{
		if (gg != -1)
			a.push_back(gg);
		else break;
	}
	if(a.size()< 6)
	{
		cout << "NONE\n";
		return;
	}
	for (int i = 0; i < a.size() - 2; i ++)
	{
		tuple<int,int,int> n = {a[i], a[i + 1], a[i + 2]};
		
		if (!id[n].empty() &&  id[n].back() + 4 <= i)
		{
			flag = 1;
			cout << a[i] << " " << a[i+1] << " " << a[i+2] << "\n";
			break;
		}
//		cout << n.a << " " << n.b << " "<< n.c <<" "<<i << endl;
		id[n].push_back(i);
	}
	if (!flag)cout << "NONE\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}
}
