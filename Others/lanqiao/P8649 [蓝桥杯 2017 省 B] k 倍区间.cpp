#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> freq(k, 0);
	int prefix = 0;
	freq[0] = 1;
	for (int i = 0; i < n; i++)
	{
		prefix = (prefix + a[i]) % k;
		freq[prefix]++;
	}
	int ans = 0;
	for (int i = 0; i < k; i++)
	{
		ans += freq[i] * (freq[i] - 1) / 2;
	}
	cout << ans << endl;
	return 0;
}