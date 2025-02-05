#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n+1);
	int maxNum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		maxNum = max(maxNum, a[i]);
	}
	cout << maxNum*2 << endl;

	return 0;
}