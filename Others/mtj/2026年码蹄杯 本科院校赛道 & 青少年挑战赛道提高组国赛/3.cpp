#include<bits/stdc++.h>
using namespace std;
#define int long long

//7
struct pt
{
	int lx, ly, rx, ry;
};
void solve()
{
	int n;
	cin >> n;
	vector<pt> px, py;
	for (int i = 1; i <= n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		px.push_back({a, b, c, d});
	}
	for (int i = 0; i < n; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			if(j == i)continue;
			if((px[i].lx<=px[j].lx&&px[j].lx<=px[i].rx)||
			   (px[j].lx<=px[i].lx&&px[i].lx<=px[j].rx))
			{
				if((px[i].ly<=px[j].ly&&px[j].ly<=px[i].ry)||
				   (px[j].ly<=px[i].ly&&px[i].ly<=px[j].ry))
				{
					cnt++;
				}
			}
		}
		cout << cnt << " ";
	}
	cout << endl;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int T = 1;
	while (T--)
	{
		solve();
	}


	return 0;
}
