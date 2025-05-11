#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e5+10;
#define int long long
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> a[i];
	}
	vector<ll> b = a;
	sort(b.begin(), b.end());
	vector<ll> c(n - 1);
	for (int j = 0; j < n - 1; j++) 
	{
		c[j] = b[j + 1] - b[j];
	}
	
	deque<int> dq;
	ll ans = INT_MAX;
	for (int j = 0; j < n - 1; j++) 
	{
		while (!dq.empty() && c[dq.back()] >= c[j])
			dq.pop_back();
		dq.push_back(j);
		if (!dq.empty() && dq.front() < j - (k - 2))
			dq.pop_front();
		if (j >= k - 2) {
			int i0 = j - (k - 2);
			ll minDiff = c[dq.front()];
			ll span    = b[i0 + k - 1] - b[i0];
			ans = min(ans, minDiff * span);
		}
	}

	cout << ans << endl;
	return 0;
}
