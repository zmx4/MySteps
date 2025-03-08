#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

void solve()
{
	string s;
	cin>>s;
	string ans="";
	ans+=s[0];
	for(int i=1;i<s.size();i+=2)
	{
		ans+=s[i];
	}
	cout<<ans<<endl;
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