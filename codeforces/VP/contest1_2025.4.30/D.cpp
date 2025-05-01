#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	if (n == k)
		{
			for (int i = 1; i <= n; i++)
			{
				cout << 1;
			}
			return 0;
		}
	vector<int> a(n + 1,0);
	int mid = ((n-k) / 2) + 1;
	for (int i = 1; i <= n;i++)
	{
		if(i%(mid)!=0)
			a[i] = 0;
		else
			a[i] = 1;
	}

		for (int i = 1; i <= n; i++)
		{
			cout << a[i] ;
		}
	return 0;
}