#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	unsigned long long n;
	cin >> n;
	unsigned long long a = 1;
	unsigned long long l = 1, r = n;
	while (l <= r)
	{
		unsigned long long mid = (l + r) / 2;
		unsigned long long cube = mid * mid * mid;
		unsigned long long cube_next = (mid + 1) * (mid + 1) * (mid + 1);
		if (cube <= n && cube_next > n)
		{
			a = mid;
			break;
		}
		else if (cube <= n)
		{
			a = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << a << endl;
	return 0;
}