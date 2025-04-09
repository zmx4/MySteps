#include <bits/stdc++.h>
#define endl "\n"
#define gcd __gcd
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 10;
vector<int> factor[N];
int lcm(int a, int b)
{
	return a / __gcd(a, b) * b;
}
int gcd3(int a, int b, int c)
{
	return __gcd(__gcd(a, b), c);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	//记录因子
	for (int i = 0; i < n;i++)
	{
		for (int j = 1; j <= a[i] / j;j++)
		{
			if(a[i] % j == 0)
			{
				factor[j].push_back(a[i]);
				if(a[i]/j!=j)
					factor[a[i] / j].push_back(a[i]);
			}
		}
	}
	for (int i = N; i >= 1;i--)
	{
		if(factor[i].size()>=3)
		{
			int fa = factor[i][0], b = factor[i][1], c = factor[i][2];
			if(gcd3(fa,b,c)==i)
			{
				//cout << format("{} {} {}", fa, b, c);
				cout << fa << " " << b << " " << c << endl;
				return 0;
			}
		}
	}
		return 0;
}