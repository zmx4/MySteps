#include <bits/stdc++.h>
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	getline(cin, s);
	istringstream iss(s);
	int x;
	int cnt = 0;
	while (iss >> x)
	{
		cnt++;
		if (x == 250)
		{
			cout << cnt;
			break;
		}
	}

	return 0;
}