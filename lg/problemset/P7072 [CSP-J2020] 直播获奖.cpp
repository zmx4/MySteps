#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
array<int, 1000> a;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, w;
	cin >> n >> w;
	for (int i = 1; i <= n;i++)
	{
		int x;
		cin >> x;
		a[x]++;
		int j = 600,sum = 0;
		for (j;j >= 0;j--)
		{
			sum+=a[j];
			if(sum>=max(1,(i*w)/100))
			{
				cout << j << " ";
				break;
			}
		}
	}
	return 0;
}