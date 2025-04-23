#include <bits/stdc++.h>
#define endl "\n"
#define gcd __gcd
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
#define int long long
void solve()
{
	int n;cin>>n;

	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	int minn = min_element(a.begin() + 1, a.end()) - a.begin();
	int num = 0;
	for(int i=1;i<=n;i++)
	{
		if(i == minn) continue;
		if(a[i] % a[minn] == 0)
		{
			num = gcd(num, a[i]);
		}
	}
	if(num == a[minn]) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	
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