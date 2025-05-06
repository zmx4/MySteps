#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i) cin>>a[i];
	int minn = *min_element(a.begin(), a.end());
	int maxx = *max_element(a.begin(), a.end());
	if(minn == maxx)
	{
		cout<<"NO"<<endl;
		return;
	}
	else
	{
		cout<<"YES"<<endl;
		for(int i = 0; i < n; ++i)
		{
			if(a[i] == maxx) cout<<1<<" ";
			else cout<<2<<" ";
		}
		cout<<endl;
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