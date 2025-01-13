#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int a[4]={0};
	int n;
	cin >> n;
	for (int i = 1; i <= 3;i++)
	{
		int c, b;
		cin >> c >> b;
		int cnt = 0;
		while(cnt<n)
		{
			cnt += c;
			a[i]+=b;
		}
	}
	cout << min(a[1], min(a[2], a[3])) << endl;
		return 0;
}