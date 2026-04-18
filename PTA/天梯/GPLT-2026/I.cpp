#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
signed main()
{
	bool flag = 0;
	int n,t;cin >> n >> t;
	vector<pair<int,int>> todo;
	int sum = 0;
	for(int i = 1;i <= n;++i)
	{
		int x;
		cin >> x;
		if(x <= t)
		{
			if(flag)cout << " ";
			cout << i;
			flag = 1;
		}
		else
		{
			todo.emplace_back(i,x);
			sum += x;
		}
	}
	while(todo.size())
	{
		reverse(todo.begin(),todo.end());
		vector<pair<int,int>> nt;
		t = sum / todo.size();
		sum = 0;
		for(auto [i,x]:todo)
		{
			
			if(x <= t)
			{
				if(flag)cout << " ";
				cout << i;
				flag = 1;
			}
			else
			{
				nt.emplace_back(i,x);
				sum += x;
			}
		}
		todo = nt;
	}
	return 0;
}
