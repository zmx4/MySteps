#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve1(void)
{
	int len = 100;
	vector<int> num(101, 0);
	for (int i = 1; i <= len; i++)
	{
		cin >> num[i];
	}
	// num[2] -= 2, num[3]--, num[0]--;
	int ans = 0;
	for (int m = 1; m <= 12; m++)
	{
		for (int d = 1; d <= days[m]; d++)
		{
			int date[] = {2, 0, 2, 3, m / 10, m % 10, d / 10, d % 10};
			int cnt = 0;
			for (int i = 1; i <= 100; i++)
			{
				if (num[i] == date[cnt])
					cnt++;
				if (cnt == 8)
				{
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}
void solve2(void)
{
	double tar = 11625907.5798;
	for (int i = 1; i <= 23333333; i++)
	{
		int j = 23333333 - i;
		double h = 0 - (i * (i / 23333333.0) * log2(i / 23333333.0) + j * (j / 23333333.0) * log2(j / 23333333.0));
		if (abs(h - tar) < 0.01)
		{
			cout << i;
			return;
		}
	}
}
int main()
{
	string ans[] = {
		"235", // 双引号中替换为 A 题的答案
		"11027421",				// 双引号中替换为 B 题的答案
	};
	char T;
	cin >> T;
	cout << ans[T - 'A'] << endl;
	return 0;
}