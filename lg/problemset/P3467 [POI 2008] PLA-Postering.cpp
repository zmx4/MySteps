#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 2e6+10;
int n;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	stack<ll> stk;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		int x;
		int y;
		cin >> y;
		cin >> x;
		while(!stk.empty()&&stk.top() > x) stk.pop();
		if(stk.empty()||stk.top()!=x)
			ans++;
		stk.push(x);
	}
	cout << ans << endl;
	return 0;
}