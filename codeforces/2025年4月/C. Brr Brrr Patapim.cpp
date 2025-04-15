#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	int n;
	cin >> n;
	vector<int> a(2*n+1);
	bool st[16000] = {false};
	memset(st, false,sizeof(st));
	for (int i = 1; i <= n;i++)
	{
		for (int j = 1; j <= n;j++)
		{
			int x;
			cin >> x;
			a[i + j] = x;
			st[x] = true;
		}
	}
	for (int i = 1; i <= 2 * n;i++)
	{
		if(a[i]!=0)
		cout<<a[i]<<" ";
		else
		{
			for (int j = 1; j <= 2 * n ;j++)
			{
				if(!st[j])
				{
					cout<<j<<" ";
					st[j] = true;
					break;
				}
			}
		}
	}
	cout<<endl;
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