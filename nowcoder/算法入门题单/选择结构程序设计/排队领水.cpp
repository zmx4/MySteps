#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, a, b;
	cin >> n >> a >> b;
	int l = n-a, r = b + 1;
	int ans=min(l, r);
	cout << ans << endl;


	return 0;
}