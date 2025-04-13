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

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), diff(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	while(m--)
	{
		int l, r, c;
		cin >> l >> r >> c;
		diff[l] += c;
		diff[r + 1] -= c;
	}
	for(int i = 1; i <= n; i++)
	{
		diff[i] += diff[i - 1];
		a[i] += diff[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}