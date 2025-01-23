#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	//int n;
	for (int i = 1; i <= 7;i++)
	{
		int x;
		cin >> x;
		if(x!=1&&x!=2&&x!=3&&x!=5&&x!=6)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}