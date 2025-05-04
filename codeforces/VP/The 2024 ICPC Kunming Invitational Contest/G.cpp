#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	if(n==1||n%4==0)
	{
		cout << "impossible" << endl;
		return;
	}
	vector<int> ans(n+1);
	for(int i=0;i<n;i++)
		ans[i] = i;
	swap(ans[0], ans[1]);
	for (int i = 3;i < n; i += 4)
	{
		swap(ans[i], ans[i + 1]);
	}
	for (int i = 0; i < n;i++)cout<<ans[i]<<" ";
	cout << endl;
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