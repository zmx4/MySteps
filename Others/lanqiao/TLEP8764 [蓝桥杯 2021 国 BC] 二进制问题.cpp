
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

long long C(long long b, long long a) // 计算组合（b在下面，a在上面）
{
	long long sum = 1;
	for (long long i = b, j = 1; j <= a; i--, j++)
		sum = sum * i / j;
	return sum;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	if(n==k&&k==1)
	{
		cout<<1<<endl;
		return 0;
	}
	int cnt = 0, ans = 0;
	for(int i = 62; i >= 0; i--)
	{
		if((n>>i)&1)
		{
			if(k==0)
			{
				cout<<ans<<endl;
				return 0;
			}
			ans += C(i, k);
			k--;
		}
	}
}