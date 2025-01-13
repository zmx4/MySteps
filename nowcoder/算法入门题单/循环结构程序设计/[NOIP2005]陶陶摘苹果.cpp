#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int a[11];
	for(int i = 1; i <= 10;i++)
	{
		cin >> a[i];
	}
	int high;cin>>high;
	high += 30;
	int ans = 0;
	for(int i = 1; i <= 10;i++)
	{
		if(a[i] <= high)
		{
			ans++;
		}
	}
	cout << ans << endl;

	return 0;
}