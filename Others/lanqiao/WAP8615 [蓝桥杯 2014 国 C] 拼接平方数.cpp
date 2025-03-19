#include <bits/stdc++.h>
using namespace std;

// 判断一个整数是否为完全平方数
bool isPerfectSquare(long long a)
{
	long long r = round(sqrt(a));
	return r * r == a;
}

bool judge(int x)
{
	string s = to_string(x);
	int len = s.size();
	for (int i = 1; i < len; i++)
	{
		string s1 = s.substr(0, i);
		string s2 = s.substr(i);
		if (s2[0] == '0')
			continue;
		long long a = stoll(s1);
		long long b = stoll(s2);
		if (a > 0 && b > 0 && isPerfectSquare(a) && isPerfectSquare(b))
			return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B;
	cin >> A >> B;
	for (int i = 1; i * i <= B; i++)
	{
		int x = i * i;
		if (x < A)
			continue;
		if (judge(x))
			cout << x << "\n";
	}
	return 0;
}