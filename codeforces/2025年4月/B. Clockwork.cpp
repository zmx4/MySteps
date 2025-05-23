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
	vector<int> a(n);
	for (int i = 0; i < n;i++)
		cin >> a[i];
	bool flag = false;
	for (size_t i = 0; i < n; i++)
	{
		if(a[i]<=max(i * 2,(n - i - 1)* 2))
		{
			flag = true;
		}
	}
	if(!flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
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