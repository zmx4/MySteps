#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
struct custom_hash
{
static uint64_t splitmix64(uint64_t x)
{
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const
{
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	unordered_map<int, int,custom_hash> cnt;
	for (int i = 0; i < n; i++)
	{
		cnt[a[i]]++;
	}
	for (int i = 1;i <= m; i++)
	{
		if (cnt[i] == 0)
		{
			cout << 0 << endl;
			return 0;
		}
	}
	int ans = 0;
	for (int i = n; i >= 0;i--)
	{
		cnt[a[i]]--;
		ans++;
		if (cnt[a[i]] == 0)
		{
			cout << ans - 1 << endl;
			return 0;
		}
	}
		return 0;
}