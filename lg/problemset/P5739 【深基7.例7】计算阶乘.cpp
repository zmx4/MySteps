#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll fact(ll n)
{
	if(n == 0)
		return 1;
	return n * fact(n - 1);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	cout << fact(n) << endl;

	return 0;
}