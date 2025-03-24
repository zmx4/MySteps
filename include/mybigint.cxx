#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	string big = s1.size() > s2.size() ? s1 : s2, small = s1.size() > s2.size() ? s2 : s1;
	array<int, 1000> a, b, c;
	fill(a.begin(), a.end(), 0);
	fill(b.begin(), b.end(), 0);
	fill(c.begin(), c.end(), 0);
	for (int i = 0; i < big.size(); i++)
		a[i] = big[big.size() - i - 1] - '0';
	for (int i = 0; i < small.size(); i++)
		b[i] = small[small.size() - i - 1] - '0';
	for (int i = 0; i < big.size(); i++)
	{
		c[i] += a[i] + b[i];
		if (c[i] >= 10)
		{
			c[i + 1] += c[i] / 10;
			c[i] %= 10;
		}
	}
	bool flag = false;
	for (int i = 999; i >= 0; i--)
	{
		if (c[i] != 0)
			flag = true;
		if (flag)
			cout << c[i];
	}
	return 0;

}
