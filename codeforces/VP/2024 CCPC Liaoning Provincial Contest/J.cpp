#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	int a, b, c;
	cin >> n;
	cin >> a >> b >> c;
	vector<pair<int, int>> stu(n);
	for (int i = 0; i < n;i++)
	{
		cin >> stu[i].first >> stu[i].second;
	}
	int x;
	cin >> x;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if(stu[i].first+stu[i].second < c)
		{
			if (stu[i].first + x > a)
				stu[i].first = a;
			else
				stu[i].first += x;
			if (stu[i].first + stu[i].second>=c)
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}