#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cctype>
using namespace std;

// 计算两个数的最大公约数（非负）
long long gcd_ll(long long a, long long b)
{
	return b == 0 ? a : gcd_ll(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	// 初始化和为0/1
	long long sum_num = 0, sum_den = 1;
	for (int i = 0; i < N; i++)
	{
		string frac;
		cin >> frac; // 格式形如 a/b
		size_t pos = frac.find('/');
		long long a = stoll(frac.substr(0, pos));
		long long b = stoll(frac.substr(pos + 1));
		// 求和： sum = sum_num/sum_den + a/b = (sum_num*b + a*sum_den) / (sum_den * b)
		long long new_num = sum_num * b + a * sum_den;
		long long new_den = sum_den * b;
		// 约分
		long long g = gcd_ll(llabs(new_num), new_den);
		new_num /= g;
		new_den /= g;
		sum_num = new_num;
		sum_den = new_den;
	}

	// 保证分母为正
	if (sum_den < 0)
	{
		sum_den = -sum_den;
		sum_num = -sum_num;
	}

	// 将结果表示为 整数部分 和 真分数部分
	long long abs_num = llabs(sum_num);
	long long whole = abs_num / sum_den;
	long long rem = abs_num % sum_den;

	// 如果结果为负，则输出时先输出负号
	string sign = (sum_num < 0) ? "-" : "";
	if (rem == 0)
	{
		// 整数结果
		cout << sign << whole;
	}
	else if (whole == 0)
	{
		// 纯分数形式（整数部分为0则直接输出分数，不输出0）
		cout << sign << rem << "/" << sum_den;
	}
	else
	{
		cout << sign << whole << " " << rem << "/" << sum_den;
	}

	return 0;
}