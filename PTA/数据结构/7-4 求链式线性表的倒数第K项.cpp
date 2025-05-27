#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

void solve()
{
	int k;
	if (!(cin >> k))
		return;

	vector<int> a;
	int x;
	while (cin >> x)
	{
		if (x < 0)
			break;
		a.push_back(x);
	}
	// 注意：当 a.size()==k 时是合法的，倒数第k个就是 a[0]
	if ((int)a.size() < k)
	{
		cout << "NULL\n";
	}
	else
	{
		cout << a[a.size() - k] << "\n";
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T = 1;//cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}