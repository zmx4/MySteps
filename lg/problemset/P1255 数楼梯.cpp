#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using u128 = unsigned __int128;
using namespace std;
const int inf = 0x3f3f3f3f;
template <typename T = int, T BASE = 10>
class BigInt
{
public:
	std::vector<T> digits; // 低位在前，高位在后

	// 默认构造
	BigInt() {}

	// 从字符串构造
	BigInt(const std::string &num)
	{
		for (auto it = num.rbegin(); it != num.rend(); ++it)
		{
			if (*it >= '0' && *it <= '9')
			{
				digits.push_back(*it - '0');
			}
			else
			{
				// 可以扩展支持字母（进制>10）
				digits.push_back(*it - 'A' + 10);
			}
		}
		trim();
	}

	// 从整数构造
	BigInt(long long num)
	{
		if (num == 0)
			digits.push_back(0);
		while (num > 0)
		{
			digits.push_back(num % BASE);
			num /= BASE;
		}
	}

	// 去掉前导零
	void trim()
	{
		while (digits.size() > 1 && digits.back() == 0)
			digits.pop_back();
	}

	// 高精度加法
	BigInt operator+(const BigInt &other) const
	{
		BigInt res;
		T carry = 0;
		size_t n = std::max(digits.size(), other.digits.size());
		for (size_t i = 0; i < n || carry; ++i)
		{
			T sum = carry;
			if (i < digits.size())
				sum += digits[i];
			if (i < other.digits.size())
				sum += other.digits[i];
			res.digits.push_back(sum % BASE);
			carry = sum / BASE;
		}
		res.trim();
		return res;
	}

	// 输出
	friend std::ostream &operator<<(std::ostream &os, const BigInt &num)
	{
		for (auto it = num.digits.rbegin(); it != num.digits.rend(); ++it)
			os << (char)((*it < 10) ? '0' + *it : 'A' + (*it - 10));
		return os;
	}
};

// 支持直接加等赋值
template <typename T, T BASE>
BigInt<T, BASE> &operator+=(BigInt<T, BASE> &lhs, const BigInt<T, BASE> &rhs)
{
	lhs = lhs + rhs;
	return lhs;
}
void climb(ll n)
{
	BigInt past = 1, now = 1 , next = 1;
	for (ll i = 2; i <= n; i++)
	{
		next = past + now;
		past = now;
		now = next;
	}
	cout << next << endl;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ull n;
	cin >> n;
	climb(n);


	return 0;
}