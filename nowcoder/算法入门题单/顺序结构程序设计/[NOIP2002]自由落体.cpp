#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	double H, S1, V, L, K;
	int n;
	double t = 0;
	const int g = 10;
	cin >> H >> S1 >> V >> L >> K >> n;
	double high = H - K;
	double t1 = sqrt(2 * high / g), t2 = sqrt(2 * H / g);
	double l1 = t1 * V, l2 = t2 * V;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		double x = i * (S1/n);
		if(x >= l1 && x <= l2)
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}