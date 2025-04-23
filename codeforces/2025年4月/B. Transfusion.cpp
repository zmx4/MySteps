#include <bits/stdc++.h>
#define endl "\n"
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
	int oddsum = 0, evensum = 0;
	int oddcnt = 0, evencnt = 0;
	for(int i=1;i<=n;i++)
	{
		if(i&1) oddsum += a[i], oddcnt++;
		else evensum += a[i], evencnt++;
	}
	if((oddsum / oddcnt == evensum / evencnt) && (oddsum % oddcnt == 0) && (evensum % evencnt == 0))
	{
		cout << "YES" << endl;
		return;
	}
	else
	{
		cout << "NO" << endl;
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