#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4+10;
signed main()
{
	int n;cin >> n;
	vector<int> a(n+1);
	int sum = 0,minn = LLONG_MAX,maxn = -1;
	for(int i = 1;i <= n;++i)
	{
		cin >> a[i];
		sum+=a[i];
		maxn = max(maxn,a[i]);
		minn = min(minn,a[i]);
	}
	cout << maxn << " " << minn << " " << sum / n << endl;
	bool flag = true;
	int ave = sum / n;
	for(int i = 1;i <= n;++i)
	{
		if(a[i]>ave*2)
		{
			if(!flag)cout << " ";
			cout << i;
			flag = 0;
		}
	}
	if(flag)
	{
		cout << "Normal" << endl;
	}
	
	return 0;
}
