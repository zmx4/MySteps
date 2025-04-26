#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
void solve()
{
	int n;
	cin >> n;
	vector<int> a(n), cnt(30);
	for (int i = 0; i < n;i++)
	{
		cin >> a[i];
		bitset<30> b(a[i]);
		for (int j = 0; j < 30; j++)
		{
			if (b[j])
				cnt[j]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < n;i++)
	{
		int sum = 0;
		for (int j = 0; j < 30;j++)
		{
			bool f = ((a[i] >> j) & 1);
			if (f)
				sum += (1<<j)*(n-cnt[j]);
			else 
				sum += (1<<j)*cnt[j];
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
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