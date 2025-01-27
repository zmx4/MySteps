#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n, a, b, c;
		cin >> n >> a >> b >> c;

		int m = a + b + c - n;
		if (m < 0)
		{
			cout << "No" << endl;
			continue;
		}

		bool flag = false;
		for (int x1 = 0; x1 <= min(a, m); x1++)
		{
			for (int x3 = 0; x3 <= min(b, m - x1); x3++)
			{
				int x5 = m - x1 - x3;
				if (x5 < 0)
					continue;
				if (x1 + x5 > c)
					continue;
				if (x3 + x5 > b)
					continue;
				if (x1 + x3 > a)
					continue;
				flag = true;
				break;
			}
			if (flag)
				break;
		}

		if(flag)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}