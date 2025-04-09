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

	int k;
	string s;
	char c1,c2;
	cin >> k >> s >> c1 >> c2;
	int n = s.size();
	ll ans = 0;
	vector<int>surffix(n+1,0);
	for(int i = n-1; i >= 0; --i)
	{
		if(s[i] == c2) surffix[i] = surffix[i+1]+1;
		else surffix[i] = surffix[i+1];
	}
	for(int i = 0; i < n; ++i)
	{
		if(s[i] == c1)
		{
			ans += surffix[min(i + k - 1, n)];
		}
	}
	cout << ans << endl;
		return 0;
}