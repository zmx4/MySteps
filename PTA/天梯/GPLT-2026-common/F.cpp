#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	while(T--)
	{
		int x;
		bool flag = 0;
		int now = 1;
		int ans = -1;
		unordered_set<int>s;
		while(cin >> x)
		{
			if(x == -1)break;
			if(s.count(x) && ans == -1)
			{
				flag = 1;
//				cout << x << endl;
//				break;
				ans = x;
			}
			now ++;
			s.insert(x);
		}
		if(!flag)cout<< "NONE" << endl;
		else cout << ans << endl;
	}
}
