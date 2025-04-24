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
		// http://xorshift.di.unimi.it/splitmix64.c
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
void solve()
{
	int n;cin>>n;
	unordered_map<int,int,custom_hash> mp;
	vector<int> a(n+1);
	ll sum = 0;
	for(int i=1;i<=n;i++) cin>>a[i], sum+=a[i] , mp[a[i]]++;
	if((sum*2)%n!=0)
	{
		cout<<0<<endl;
		return;
	}
	ll ave = sum * 2 / n;
	ll ans = 0;
	for(int i=1;i<=n;i++)
	{
		int need = ave - a[i];
		if(mp.count(need))
		{
			if(need == a[i])
			{
				ans += mp[need] - 1;
			}
			else
			{
				ans += mp[need];
			}
		}
	}
	cout<<ans/2<<endl;
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