#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using LL = long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5+10;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int a,b;
	cin >> a >> b;
	double ans = (double)a / b;
	if(ans-(a/b)<0.5)
	{
		cout << (int)ans << endl;
	}
	else
	{
		cout << (int)ans + 1 << endl;
	}







	return 0;
}