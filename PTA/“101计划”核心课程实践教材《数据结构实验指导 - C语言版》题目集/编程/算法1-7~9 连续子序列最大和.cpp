#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int n;
	cin >> n;
	vector<int> a(n);
	bool flag = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] > 0)
			flag = true;
	}
	if (!flag)
	{
		cout << 0 << endl
			 << "-1 -1" << endl;
		return 0;
	}
	int sum = 0, ans = 0, l = 0, r = 0, templ = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		if (sum > ans)
		{
			ans = sum;
			l = templ;
			r = i;
		}
		if (sum < 0)
		{
			sum = 0;
			templ = i + 1;
		}
	}
	cout << ans << endl
		 << l + 1 << " " << r + 1 << endl;

	return 0;
}