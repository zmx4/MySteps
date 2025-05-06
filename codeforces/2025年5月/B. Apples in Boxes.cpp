#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin >> a[i];
	ll sum = accumulate(a.begin(), a.end(), 0LL);
	if(sum%2==0)
	{
		cout << "Jerry" << endl;
		return;
	}
	sort(a.begin(), a.end());
	a.back()--;
	sort(a.begin(), a.end());
	if(a.back()-a.front() > k)
	{
		cout << "Jerry" << endl;
		return;
	}
	else
	{
		cout << "Tom" << endl;
		return;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}