#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int stk[100010], tt;

signed
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans[100010];
	for (int i = n ; i > 0;i--)
	{
		int x = a[i];
		while(tt&&a[stk[tt]]<=x)tt--;
		if(tt)ans[i] = stk[tt];
		else ans[i] = 0;
		stk[++tt] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}