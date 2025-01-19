#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int k;cin>>k;
	int cnt = 0;
	double sum = 0;
	while(sum <= k)
	{
		cnt++;
		sum += 1.0/cnt;
	}
	cout<<cnt<<endl;
	return 0;
}