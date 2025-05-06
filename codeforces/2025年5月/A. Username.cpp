#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	string s;
	cin >> s;
	int n = s.size();
	for (int j = n - 1; j >= 1; --j)
	{
		if (isdigit(s[j]) && s[j] != '0')
		{
			bool all_digits = true;
			for (int k = j; k < n; ++k)
			{
				if (!isdigit(s[k]))
				{
					all_digits = false;
					break;
				}
			}
			if (!all_digits)
				continue;
			bool has_letter = false;
			for (int k = 0; k < j; ++k)
			{
				if (islower(s[k]))
				{
					has_letter = true;
					break;
				}
			}
			if (!has_letter)
				continue;
			cout << s.substr(0, j) << "\n";
			return;
		}
	}
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