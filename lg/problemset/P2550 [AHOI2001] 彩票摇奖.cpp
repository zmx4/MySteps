	#include <bits/stdc++.h>
	#define endl "\n"
	#define ll long long
	using namespace std;
	unordered_set<int> s;
	int a[8];
	void solve()
	{
		int ans = 0;
		for (int i = 1; i <= 7; i++)
		{
			int x;
			cin >> x;
			if(s.count(x))
				ans++;
		}
		a[7 - ans]++;
	}

	signed main()
	{
		ios::sync_with_stdio(false);
		cin.tie(nullptr),cout.tie(nullptr);
		char readBuffer[1 << 20];
		cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

		int T;cin>>T;
		for (int i = 1; i <= 7;i++)
		{
			int x;
			cin >> x;
			s.insert(x);
		}
		while (T--)
		{
			solve();
		}
		for(int i = 0; i < 7;i++)
			cout << a[i] << " ";
		return 0;
	}