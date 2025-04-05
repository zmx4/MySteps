#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

struct comp
{
	int start, end;
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<comp> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i].start >> a[i].end;
	sort(a.begin(), a.end(), [](comp x, comp y) {
		return x.end < y.end ;
	});
	int ans = 0, last = 0;
	for (int i = 0; i < n; ++i) 
	{
		if (a[i].start >= last) 
		{
			ans++;
			last = a[i].end;
		}
	}
	cout << ans << endl;
	return 0;
}