#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int n, l;cin>>n>>l;
	vector<int> a(n);
	for(int i=0;i<n;++i)cin>>a[i];
	sort(a.begin(), a.end());

	double max_dist = 0;
	for (int i = 0; i < n;i++)
	{
		if (i == 0)
		{
			max_dist = a[i];
		}
		else
		{
			max_dist = max(max_dist, (a[i] - a[i - 1]) / 2.0);
		}
	}
	printf("%.10f\n", max(max_dist, (double)l - a[n - 1]));
	//printf("%.10f\n", max_dist);
	return 0;
}