#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int r, x;
	cin >> r >> x;
	bool ans = false;
	if(x==1)
	{
		if(r>=1600&&r<=2999)ans = true;
	}
	else
	{
		if(r >= 1200 && r <= 2399)ans = true;
	}
	if(ans)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}