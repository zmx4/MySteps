#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
/*
ahaahahahahahahaahaahahahahha
114514
hehhahaahahahaahaahahaaaahaa
1919810
*/
void solve()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << "nunhehheh" << "\n";
		return;
	}
	int best_r = -1, best_t = -1;
	for (int r = 31; r >= 1; r--)
	{
		ll div = ((1LL << r) - 1);
		if (n % div == 0)
		{
			int t = n / div;
			if (t <= 100000)
			{
				best_r = r;
				best_t = t;
				break;
			}
		}
	}
	if (best_r == -1)
	{
		best_r = 1;
		best_t = n;
	}
	string prefix = "nunhehheh";
	string ans;
	for (int i = 0; i < best_t; i++)
	{
		ans += prefix;
		ans.push_back('b');
	}
	if (!ans.empty() && ans.back() == 'b')
		ans.pop_back();
	ans += string(best_r, 'a');
	cout << ans << endl;
}


signed
main()
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