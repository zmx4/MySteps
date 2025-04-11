#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e9 + 7;
const int M = 1e5 + 5;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, ma;
	cin >> n >> ma;
	vector<int> a(M, 0);
	for (int i = ma - 1; i >= 0; i--)
	{
		cin >> a[i];
	}
	int mb;
	cin >> mb;
	vector<int> b(M,0);
	for (int i = ma - 1; i >= 0; i--)
	{
		cin >> b[i];
	}
	ll ans = 0;
	for (int i = max(ma, mb) - 1; i >= 0; i--)
	{
		ans = (ans * max(2, max(a[i] + 1, b[i] + 1)) + a[i] - b[i] + N) % N;
	}
	cout << ans << endl;
		return 0;
}