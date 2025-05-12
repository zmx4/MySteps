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
	string s;
	cin >> s;
	if (s[0] != s[n - 1])
	{
		cout << "empty" << endl;
		return;
	}
	char c = s[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (s[i] != c && s[i + 1] != c)
		{
			cout << "empty" << endl;
			return;
		}
	}
	bool flag = true;
	int ans = INT_MAX, cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == c)
		{
			if (flag)
			{
				cnt++;
			}
			else
			{
				flag = true;
				cnt = 1;
			}
		}
		else
		{
			flag = false;
			ans = min(ans, cnt);
			cnt = 0;
		}
	}
	ans = min(ans, cnt);
	for (int i = 0; i < ans; i++)
		cout << c;
	cout << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	while (T--)
	{
		solve();
	}

	return 0;
}