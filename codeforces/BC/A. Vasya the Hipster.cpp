#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int a, b;
	cin >> a >> b;

	int popularday = min(a, b);
	int totalDay;
	if (max(a, b) - popularday >= 2)
		totalDay = (max(a, b) - popularday) / 2;
	else
		totalDay = 0;
	cout << popularday << " " << totalDay;

	return 0;
}