#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int m, k;
	cin >> m >> k;
	vector<int> zw;
	while(m--)
	{
		string op;
		int num;
		cin >> op >> num;
		if(op=="add")
			if(zw.empty())zw.push(num);
			else
			{
				int index = zw.lower_bound(num);
				if(index == zw.end()&&abs(zw.top()-num)<k)zw.push(num);
				else if(index == zw.begin()&&abs(zw.top()-num)<k)zw.push(num);
				else if(abs(*index-num)<k)zw.push(num);
				sort(zw.begin(),zw.end(),greater<int>());
			}
		else if (op == "del")
		{
			if(!zw.empty())
			{
				int index = zw.lower_bound(num);
				if(index == zw.end()&&abs(zw.top()-num)<k)zw.pop();
				else if(index == zw.begin()&&abs(zw.top()-num)<k)zw.pop();
				else if(abs(*index-num)<k)zw.pop();
				sort(zw.begin(), zw.end(), greater<int>());
			}
		}
		else if (op == "query")
		{
			if(zw.empty())cout << "null" << endl;
			else cout << zw.top() << endl;
		}
	}

	return 0;
}