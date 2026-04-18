#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	int cnt = 0,sum = 0;
	for(int i = 1;i <= n;++i)
	{
		int x;cin >> x;
		if(x >=	 1700)
		{
			cnt++;
			sum += x;
		}
	}
	cout << n - cnt << endl;
	return 0;
}
