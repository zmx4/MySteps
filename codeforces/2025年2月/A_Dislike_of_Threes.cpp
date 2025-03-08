#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

vector<int> v;
void pre()
{
	for(int i=1;i<=2000;i++)
	{
		if(i%3==0 || i%10==3)
			continue;
		v.push_back(i);
	}
}

void solve()
{
	int n;cin>>n;
	cout<<v[n-1]<<endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	pre();
	while(T--)
	{
		solve();
	}
	
	return 0;
}