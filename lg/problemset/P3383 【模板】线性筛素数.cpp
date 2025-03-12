#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
std::vector<int> generatePrimesSieve(int l, int r)
{
	// 构造大小为 r+1 的布尔数组，初始值全部设为 true
	std::vector<bool> isPrime(r + 1, true);

	// 0 和 1 不是质数
	if (r >= 0)
		isPrime[0] = false;
	if (r >= 1)
		isPrime[1] = false;

	// 遍历到 sqrt(r)，因为超过 sqrt(r) 的 i 没有必要再筛
	int limit = std::sqrt(r);
	for (int i = 2; i <= limit; i++)
	{
		if (isPrime[i])
		{
			// 从 i*i 开始标记所有 i 的倍数为非质数
			for (int j = i * i; j <= r; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

	// 收集大于等于 l 的质数（注意：质数起始从 2 开始）
	std::vector<int> primes;
	for (int i = std::max(l, 2); i <= r; i++)
	{
		if (isPrime[i])
		{
			primes.push_back(i);
		}
	}
	return primes;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	auto primes = generatePrimesSieve(0, n);
	while(m--)
	{
		int x;
		cin >> x;
		cout<<primes[x-1]<<endl;
	}

	return 0;
}