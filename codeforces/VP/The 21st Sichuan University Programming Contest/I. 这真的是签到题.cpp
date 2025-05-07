#include <bits/stdc++.h>
#define endl endl
#define int long long
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e6 + 10;
bool isPrime[N];
bool in[N];
void sieve()
{
	fill(isPrime, isPrime + N, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < N; i++)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < N; j += i)
				isPrime[j] = false;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve();

	int n;
	cin >> n;
	set<int, greater<int>> st;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		st.insert(x);
		in[x] = true;
	}

	for (int x : st)
	{
		bool flag = true;
		int y = x;
		for (int j = 2; j * j <= y; j++)
		{
			if (y % j == 0)
			{
				if (!in[j])
				{
					flag = false;
					break;
				}
				while (y % j == 0)
					y /= j;
			}
		}
		if (flag && y > 1 && !in[y])
			flag = false;
		if (flag)
		{
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}