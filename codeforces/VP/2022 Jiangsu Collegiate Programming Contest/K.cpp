#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	if(n==0)
	{
		cout << "qwq" << endl;
		return;
	}
	else if (n == 1)
	{
		cout << "nunhehheha" << endl;
		return;
	}
	string ans = "";
	vector<int> a;
	ll cnt = 0;
	for(int i = 1; i <= 30; i++)
	{
		if (n & (1 << i))
			a.push_back(i - 1), ++cnt;
	}
	if (n & 1)
		++cnt;
	int pre = 0;
	bool f = 1;
	for(auto i : a)
	{
		for (int j = 1; j <= i - pre; ++j)
		{
			ans += "a";
		}
		ans += "h";
		pre = i;
	}
	reverse(ans.begin(), ans.end());
	for (int j = 1; j <= cnt; ++j)
		ans += "h";
	ans += "a";
	cout << "nunhehhe" + ans << '\n';
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}