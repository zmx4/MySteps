#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
struct hum
{
	int t,index;
};

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	//vector<int> a(n);
	//for (int i = 0; i < n; ++i) cin >> a[i];
	vector<hum> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i].t, a[i].index = i;
	sort(a.begin(), a.end(), [](hum x, hum y) {
		return x.t < y.t|| (x.t == y.t && x.index < y.index);
	});
	ll tt = 0;
	for (int i = 0;i < n; ++i) 
	{
		tt += ((ll)a[i].t * (n - i - 1));
		cout << a[i].index+1  << " ";
	}
	cout << endl;
	cout << format("{:.2f}", ((double)tt / n)) << endl;
	return 0;
}