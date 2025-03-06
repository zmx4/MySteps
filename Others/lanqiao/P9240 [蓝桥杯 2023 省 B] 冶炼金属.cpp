#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int t;
	cin>>t;
	int maxn=INT_MAX,minn=0;
	while(t--)
	{
		int a, b;
		cin>>a>>b;
		
		maxn = min(maxn, a/b);

		minn = max(minn, a / (b + 1) + 1);
	}
	cout<<minn<<" "<<maxn<<endl;
	return 0;
}