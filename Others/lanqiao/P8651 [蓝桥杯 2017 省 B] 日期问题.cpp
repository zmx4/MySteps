#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int st = 1960, ed = 2050;
int days[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
inline bool isLeap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) return true;
	return false;
}
signed main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(nullptr),cout.tie(nullptr);
	int a, b, c;
	scanf("%d/%d/%d", &a, &b, &c);
	for(int i = st; i <= ed; i++)
	{
		days[2] = isLeap(i) ? 29 : 28;
		for(int j = 1; j <= 12; j++)
		{
			for(int k = 1; k <= days[j]; k++)
			{
				if ((a == i % 100 && b == j && c == k) ||
					(a == j && b == k && c == i % 100) ||
					(a == k && b == j && c == i % 100))
					printf("%d-%02d-%02d\n", i, j, k);
			}
		}
	}
	return 0;
}