#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string be, af;
	cin >> be >> af;
	int l = -1,ans = 0;
	for (int i = 0; i < be.size();i++)
	{
		if(be[i]!=af[i] && l == -1)
		{
			l = i;
		}
		else if (be[i] != af[i])
		{
			ans += i - l;
			l = -1;
		}
	}
	cout << ans << endl;
	return 0;
}