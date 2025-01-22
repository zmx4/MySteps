#include <bits/stdc++.h>
using namespace std;

static const int MAXN = 200000;

static inline vector<int> getDivisors(int x)
{
	vector<int> divisors;
	for (int i = 1; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			divisors.push_back(i);
			if (i * i != x)
			{
				divisors.push_back(x / i);
			}
		}
	}
	return divisors;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<long long> cnt(MAXN + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		cnt[x]++;
	}
	long long ans = 0;
	for (int x = 1; x <= MAXN; x++)
	{
		if (cnt[x] == 0)
			continue;
		vector<int> divisors = getDivisors(x);
		for (int d : divisors)
		{
			int y = x + d;
			if (y <= MAXN)
			{
				if (((x / d) % 2) == 0)
				{
					ans += cnt[x] * cnt[y];
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}