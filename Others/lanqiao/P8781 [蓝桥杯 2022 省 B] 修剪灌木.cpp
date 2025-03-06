#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 1; i <= n;i++)
	{
		cout<<max(2*(i-1),2*(n-i))<<endl;
	}

		return 0;
}