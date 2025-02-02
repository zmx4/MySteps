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
		int n, m;
		cin >> n >> m;
		int ans = max(n, m)+1;
		cout << ans << endl;
	}

	return 0;
}