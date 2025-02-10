#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	/*
	1 8 16 
	1 9 25 49 81 121 169 225 289 361
	*/
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int ans = 0;
		int cnt = 1;
		int sum = 0;
		for (int i = 1; i <= n; i++)
		{
			
			int a;
			cin >> a;
			sum += a;
			while (sum >= cnt * cnt)
			{
				if (sum == cnt * cnt)
					ans++;
				cnt += 2;
			}
			//cout << cnt << " " << sum << " " << ans << endl;
		}
		cout<<ans<<endl;
	}

	return 0;
}