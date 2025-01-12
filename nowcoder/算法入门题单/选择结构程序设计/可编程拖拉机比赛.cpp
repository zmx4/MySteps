#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	int ans1 = 0, ans2, ans3;
	if ((int)(n * 0.10) != n * 0.10)
		ans1 = 1;
	if ((int)(n * 0.20) != n * 0.20)
		ans2 = ans1 + 1;
	else
		ans2 = ans1;
	if ((int)(n * 0.30) != n * 0.30)
		ans3 = ans2 + 1;
	else
		ans3 = ans2;
	cout << ans1 << " " << ans2 << " " << ans3 << endl;
	return 0;
}