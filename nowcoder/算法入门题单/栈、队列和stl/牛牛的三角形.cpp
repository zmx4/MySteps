#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n;i++)cin >> a[i];
	sort(a, a + n);
	if(n<3)
	{
		cout << "No solution" << endl;
		return 0;
	}
	for (int i = 0; i < n - 2;i++)
	{
		if(a[i]+a[i+1]>a[i+2])
		{
			cout << a[i] << " " << a[i + 1] << " " << a[i + 2] << endl;
			return 0;
		}
	}
	cout << "No solution" << endl;
	return 0;
}