#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	list<int> l;
	int n;
	while (cin >> n)
	{
		if (n == -1)
			break;
		l.push_back(n);
	}
	int len = l.size();
	l.reverse();
	int cnt = 0;
	int k;
	cin >> k;
	if (k > len)
	{
		cout << "NULL" << endl;
		return 0;
	}
	for (auto i : l)
	{
		cnt++;
		if (cnt == k)
		{
			cout << i << endl;
			break;
		}
	}
	return 0;
}