#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
int f[N];

void solve()
{
	int n,m;
	cin >> n >> m;
	unordered_map<int,int> s;
	int x;
	while(cin >> x)
	{
		s[x]++;
	}
	vector<int>ans;
	for(int i = 1;i <= m;i++)
	{
		if(s[i]<= 1)ans.push_back(i);
	}
	for(int i = 0;i < 3;i++)
	{
		cout << s[i];
		if(i != 2)cout << " ";
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 1;
//	cin >> T;
	while (T--)
	{
		solve();
	}
}
