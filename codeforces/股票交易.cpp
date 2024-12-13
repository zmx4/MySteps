#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int days;cin>>days;
	vector<int> prices(days);
	for(int i=0;i<days;i++) cin>>prices[i];

	vector<int> b(days,0);
	vector<int> s(days,0);
	for (int i = 1;i < days;i++)
	{
		b[i] = prices[i] - prices[i - 1];
	}
	
		return 0;
}