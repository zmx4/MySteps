#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct pos
{
	int x, y;
	ll dis;
};

bool cmp(pos a, pos b)
{
	if (a.dis == b.dis)
	{
		if (a.x == b.x)
		{
			return a.y < b.y;
		}
		return a.x < b.x;
	}
	return a.dis < b.dis;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;
	cin >> T;
	pos p[15];
	for (int i = 0; i < T; i++)
	{
		cin >> p[i].x >> p[i].y;
		p[i].dis = (ll)p[i].x * p[i].x + (ll)p[i].y * p[i].y;
	}
	sort(p, p + T, cmp);
	for (int i = 0; i < T; i++)
	{
		cout << p[i].x << " " << p[i].y << " " << p[i].dis << endl;
	}
	return 0;
}