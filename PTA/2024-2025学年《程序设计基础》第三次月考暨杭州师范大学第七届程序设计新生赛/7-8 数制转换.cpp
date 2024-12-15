#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (bitset<32>(i).count() % 2 != 0)
		{
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}