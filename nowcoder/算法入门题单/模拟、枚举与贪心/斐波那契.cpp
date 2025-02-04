#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll fibonacci(ll n)
{
	double phi = (1 + std::sqrt(5)) / 2; // 黄金比例
	return static_cast<ll>((std::pow(phi, n) - std::pow(1 - phi, n)) / std::sqrt(5));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	ll n;
	string num;
	cin >> num;
	n = num[num.size()-1] - '0';
	if(n%2==1)
	{
		cout << "-1" << endl;
	}
	else
	{
		cout << "1" << endl;
	}

	return 0;
}