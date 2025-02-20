#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 3e7 + 5;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> spf(n + 1, 0); // 存储1~n每个数的最小质因子，若没有则为0。f(1)=0
	// 从2开始求最小质因子
	for (int i = 2; i <= n; i++)
	{
		if (spf[i] == 0)
		{ // i质数
			spf[i] = i;
			if ((ll)i * i <= n)
			{
				for (int j = i * i; j <= n; j += i)
				{
					if (spf[j] == 0)
						spf[j] = i;
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += spf[i]; 
	}
	cout << ans << endl;

	return 0;
}