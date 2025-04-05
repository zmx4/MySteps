#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e9 + 5;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	unordered_map<int,int> mp;
	for(int i = 0; i < n; i++)
	{
		int x;cin>>x;
		mp[x]++;
	}
	int ans = 0;
	for (int i = 0; i <= N; i++)if(mp[i]==0)
	{
		ans = i;
		break;
	}
	cout<<ans<<endl;

		return 0;
}