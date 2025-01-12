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
	int ans = (n / 7) * 15;
	if (n % 7 <= 5 && n % 7!=0)
		ans += (n % 7)*3;
	else if (n % 7 <= 7 && n % 7 != 0)
		ans += 15;
	cout << ans << endl;
	return 0;
}