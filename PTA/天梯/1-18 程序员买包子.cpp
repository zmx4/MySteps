#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m, k;
	string x;
	cin >> n >> x >> m >> k;
	if(k==n)
		cout << "mei you mai " << x << " de" << endl;
	else if(k==m)
		cout << "kan dao le mai " << x << " de" << endl;
	else
		cout << "wang le zhao mai " << x << " de" << endl;
	return 0;
}