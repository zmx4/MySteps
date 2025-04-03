#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;



signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	stack<int> s;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		s.push(x);
	}
	for(int i = 0; i <= n; i++)
	{
		if(!s.empty())
		{
			cout << s.top() << endl;
			s.pop();
		}
		else
		{
			cout << "错误：栈为空。" << endl;
			cout<<-1<< endl;
			cout << "错误：栈为空。" << endl;
		}
	}
	return 0;
}