#pragma once
#include <string>
#include <cstring>
#include <cstdlib>
namespace myalg
{
	
	class myalg
	{
	public:
		// 求最大公约数
		int GCD1( int a, int b)
		{
			while (b != 0)
			{
				int r = a % b;
				a = b;
				b = r;
			}
			return a;
		}
		// 递归求最大公约数
		int GCD2(int a, int b)
		{
			if (b == 0)
				return a;
			else
				return GCD2(b, a % b);
		}
		// 求最小公倍数
		int lcm(int a, int b)
		{
			return a * b / GCD1(a, b);
		}
		// 埃氏筛质数
		int countPrimes(const int &n)
		{
			if (n < 3)
				return 0;
			int count = 0;
			bool state[n];
			for (int i = 2; i < n; i++)
			{
				state[i] = false;
			}
			for (int i = 2; i * i < n; i++)
			{
				if (!state[i])
				{
					for (int j = i * i; j < n; j += i)
						state[j] = true;
				}
			}
			for (int i = 2; i < n; i++)
			{
				if (!state[i])
					count++;
			}
			return count;
		}
		// 使用埃氏筛算法生成区间 [l, r] 内的质数
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
		//求曼哈顿距离
		int manhattanDistance(int x1, int y1, int x2, int y2)
		{
			return std::abs(x1 - x2) + std::abs(y1 - y2);
		}
		// 快速幂
		long long modExp(long long base,long long exp,const long long &mod)
		{
			long long result = 1;
			base = base % mod; // 处理 base 大于 mod 的情况
			while (exp > 0)
			{
				// 如果 exp 是奇数，将 base 乘到结果上
				if (exp % 2 == 1)
				{
					result = (result * base) % mod;
				}
				// exp 是偶数，将 base 平方并减少 exp 一半
				base = (base * base) % mod;
				exp = exp / 2;
			}
			return result;
		}
	};
	
	class mysort
	{
	public:
		virtual void quicksort(int a[], int l, int r);
		virtual void insertsort(int a[], int n);
	};
	class uppersort : public mysort
	{
	public:
		virtual void quicksort(int a[], int l, int r)
		{
			if (l < r)
			{
				int i = l;
				int j = r;
				int key = a[l];
				while (i < j)
				{
					while (i < j && a[j] >= key)
						j--;
					a[i] = a[j];
					while (i < j && a[i] <= key)
						i++;
					a[j] = a[i];
				}
				a[i] = key;
				quicksort(a, l, i - 1);
				quicksort(a, i + 1, r);
			}
		}
		virtual void insertsort(int a[], int n)
		{
			for (int j = 1; j < n; j++)
			{
				int key = a[j];
				int i = j - 1;
				while (i >= 0 && a[i] > key)
				{
					a[i + 1] = a[i];
					i--;
				}
				a[i + 1] = key;
			}
		}
	};
	class lowwersort : public mysort
	{
	public:
		virtual void insertsort(int a[], int n)
		{
			for (int j = 1; j < n; j++)
			{
				int key = a[j];
				int i = j - 1;
				while (i >= 0 && a[i] < key)
				{
					a[i + 1] = a[i];
					i--;
				}
				a[i + 1] = key;
			}
		}
		virtual void quicksort(int a[], int l, int r)
		{
			if (l < r)
			{
				int i = l;
				int j = r;
				int key = a[l];
				while (i < j)
				{
					while (i < j && a[j] <= key)
						j--;
					a[i] = a[j];
					while (i < j && a[i] >= key)
						i++;
					a[j] = a[i];
				}
				a[i] = key;
				quicksort(a, l, i - 1);
				quicksort(a, i + 1, r);
			}
		}
	};
	class myjudge
	{
	private:
		long long powa(int n, int s)
		{
			long long total = 1;
			while (s--)
			{
				total *= n;
			}
			return total;
		}
		unsigned long long countDigits(int number)
		{
			int count = 0;
			if (number == 0)
				return 1;
			while (number != 0)
			{
				number /= 10;
				count++;
			}
			return count;
		}

	public:
		// 判断是否是质数
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
		// 判断是否是水仙花数
		bool isNarcissistic(const int &n)
		{
			int numDigits = countDigits(n);
			int numDIgitsA = numDigits;
			int sum = 0, temp = n;
			while (numDIgitsA--)
			{
				int a = temp % 10;
				sum += powa(a, numDigits);
				temp /= 10;
			}
			if (sum == n)
				return true;
			else
				return false;
		}
		// 判断是否是闰年
		bool isLeapYear(const int &year)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
				return true;
			else
				return false;
		}
		// 判断是否是回文数
		bool isPalindrome(string_view str)
		{
			int i = 0, j = str.size() - 1;
			while (i < j)
			{
				if (str[i] != str[j])
					return false;
				i++;
				j--;
			}
			return true;
		}
	};
} // namespace myalg
