#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin>>T;
	while(T--)
	{
		int k;
		cin>>k;
		vector<int> a = {2,0,3,3,1,3,3,1,3,3},b={4,2,2,2,3,2,3,2,4,3};
		cout<<a[k]<<' '<<b[k]<<endl;
	}

	return 0;
}