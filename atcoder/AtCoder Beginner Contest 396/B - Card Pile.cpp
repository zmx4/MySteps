#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	stack<int> s;
	int n;cin>>n;
	while(n--)
	{
		int x;cin>>x;
		if(x==2)
		{
			if(s.empty())
			{
				cout << "0" << endl;
			}
			else
			{
				cout << s.top() << endl;
				s.pop();
			}
		}
		else
		{
			int y;cin>>y;
			s.push(y);
		}
	}








	return 0;
}