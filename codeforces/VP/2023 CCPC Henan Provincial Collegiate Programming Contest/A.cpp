#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	string str;
	cin >> str;
	auto unique = [&](const string &s) -> bool
	{
		int n = s.size();
		if(n==0)
			return false;
		if (n == 1)
			return true;
		if (n > 26)
			return false;
		unordered_set<char> st;
		for (int i = 0; i < n; i++)
		{
			if (st.count(s[i]))
				return false;
			st.insert(s[i]);
		}
		return true;
	};
	auto ishuiwen = [&](const string &s) -> bool
	{
		int n = s.size();
		if(n==0)
			return false;
		if (n == 1)
			return true;
		for (int i = 0; i < n / 2; i++)
		{
			if (s[i] != s[n - i - 1])
				return false;
		}
		return true;
	};
	int n = str.size();
	
	for (int i = 0; i < min(n - 1,26);i++)
	{
		string substr1 = str.substr(0, i + 1);
		string substr2 = str.substr(i + 1);
		if (unique(substr1) && ishuiwen(substr2))
		{
			cout << "HE" << endl;
			return;
		}
	}
	cout << "NaN" << endl;
	return;
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