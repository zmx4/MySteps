#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, k;
	cin>> n >> k;
	if(n==1)
	{
		cout << k << endl;
		return;
	}
	bitset<32> m(k);
	int index = 0;
	for (int i = 0; i < 31; i++)
	{
		if(m[i])
		{
			index = i;
		}
	}
	int a = (1LL << index) - 1;
	int b = k - a;
	cout << a << " " << b;
	for (int i = 2;i < n; i++)
	{
		cout << " " << 0;
	}
	cout << endl;
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