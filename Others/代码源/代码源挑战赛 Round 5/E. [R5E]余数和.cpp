#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

void test(int n)
{
	ll sum = 0;
	for (int i = 1; i <= n;i++)
	{
		sum += n%i;
	}
	cout << sum <<" "<< n<< endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	ll sum = 0;
	for (int i = 1; i <= n;i++)
	{
		sum += n%i;
	}
	cout << sum << endl;
	return 0;
}