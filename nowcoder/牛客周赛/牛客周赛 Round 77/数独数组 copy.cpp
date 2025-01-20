#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	ll n;
	cin >> n;

	vector<int> a(10, 0);

	for (ll i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x < 1 || x > 9)
		{
			cout << "NO";
			return 0;
		}
		a[x]++;
	}
	ll maxN=-1,minN=INT_MAX;
	ll f = n / 9;
	for (int i = 1; i <= 9; i++)
	{
		if(a[i]>maxN)
		{
			maxN=a[i];
		}
		if(a[i]<minN)
		{
			minN=a[i];
		}
	}
	if(maxN-minN>1)
	{
		cout << "NO";
		return 0;
	}
	cout << "YES";

	return 0;
}
/*
98765432123456789

*/