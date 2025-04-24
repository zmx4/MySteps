#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{

	int n;cin>>n;
	vector<int> a(n);
	for(int &i:a)cin>>i;
	auto it = min_element(a.begin(), a.end()) - a.begin();
	int minVal = a[it];
	int cnt = 0;
	vector<int> b;
	for(int i = 0; i < n; i++)
	{
		if(a[i]%minVal != 0)
		{
			b.push_back(a[i]);
		}
		
	}
	if(b.empty())
	{
		cout<<"Yes"<<endl;
		return;
	}
	else 
	{
		int minn = *min_element(b.begin(), b.end());
		for(int i = 0; i < b.size(); i++)
		{
			if(b[i] % minn != 0)
			{
				cout<<"No"<<endl;
				return;
			}
		}
		cout<<"Yes"<<endl;
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