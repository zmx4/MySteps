#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int t;
	cin >> t;
	while(t--)
	{
		int n, a, b;
		cin >> n >> a >> b;
		if(abs(a-b)%2==0)
		{
			cout << "YES" << endl;

		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}