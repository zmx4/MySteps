#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
#define int unsigned long long
int lcm(int a, int b)
{
	return a / gcd(a, b) * b;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;

	return 0;
}