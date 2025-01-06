#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 1e6 + 10;
int q[N], hh, tt = -1;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int x;
	cin >> x;
	q[++tt] = x;
	hh++;
	cout << q[hh] << q[tt];

	return 0;
}