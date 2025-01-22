#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isprime(int n)
{
	if (n <= 1)
		return false;
	for (int i = 2; i <= sqrt(n);i++)
	{
		if (n%i==0)
			return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	int a[30];
	memset(a, 0, sizeof(a));
	for (int i = 0; i < s.length();i++)
	{
		a[s[i]-'a']++;
	}
	int maxn = 0, minn = 100;
	for (int i = 0; i < 26;i++)
	{
		if(a[i]>maxn)
			maxn = a[i];
		if(a[i]<minn && a[i]!=0)
			minn = a[i];
	}
	if(isprime(maxn-minn))
		cout << "Lucky Word" << endl << maxn - minn << endl;
	else
		cout << "No Answer" << endl << 0 << endl;
	return 0;
}