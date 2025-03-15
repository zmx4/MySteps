#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	double a, b, c, d;
	cin >> a >> b >> c >> d;
	int cnt = 0;
	for (double i = -100; i <= 100; i += 0.001)
	{
		double x = i,y = x + 0.001;
		if((a*x*x*x + b*x*x + c*x + d) * (a*y*y*y + b*y*y + c*y + d) < 0)
		{
			cout << format("{:.2f} ", x);
			cnt++;
		}
		if(cnt == 3)
			break;
	}
	
		return 0;
}