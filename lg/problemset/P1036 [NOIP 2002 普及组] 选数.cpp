#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
int n, k;
vector<int> a;
const int N = 5e6 + 10;
bool isPrime(const int &n)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
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
int ans;
bool used[N];
void dfs(int index, int count, int sum)
{
	if (count == k)
	{
		if (isPrime(sum))
			ans++;
		return;
	}
	if (index >= n)
		return;
	if (n - index < k - count)
		return;

	dfs(index + 1, count + 1, sum + a[index]);

	dfs(index + 1, count, sum);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n >> k;
	a.resize(n);
	for(auto &i:a)
		cin >> i;
	ranges::sort(a);
	//int maxpri = accumulate(a.end() - k, a.end(), 0);
	//vector<int> primes = generatePrimesSieve(2, maxpri);
	dfs(0, 0,0);
	cout << ans << endl;
	return 0;
}