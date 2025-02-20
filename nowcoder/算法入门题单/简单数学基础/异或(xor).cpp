#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
/*


*/
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	long long n;
	while (cin >> n)
	{
		long long full = n / 3;
		long long rem = n % 3;
		long long ans = full * 2 + min(rem, (long long)2);
		cout << ans << "\n";
	}

	return 0;
}