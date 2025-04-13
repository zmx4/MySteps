#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

queue<int> a,b;
ll n,suma,sumb;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	cin >> n;
	/*
	for (int i = 1; i <= n+1;++i)
	{
		a.push(i);
		suma+= i * i;
	}
	for (int i = n + 2;i<=2*n+1;++i)
	{
		b.push(i);
		sumb+= i * i;
	}
	for (int i = 2 * n + 1;suma!= sumb;++i)
	{
		suma -= a.front() * a.front();
		sumb -= b.front() * b.front();
		suma+= b.front() * b.front();
		a.pop();
		a.push(b.front());
		b.pop();
		sumb+=(b.back() + 1) * (b.back() + 1);
		b.push(b.back() + 1);
	}
	while(a.size()>1)
	{
		cout << a.front() << "^2 + ";
		a.pop();
	}
	cout << a.front() << "^2 =" << endl;
	a.pop();
	while (b.size() > 1)
	{
		cout << b.front() << "^2 + ";
		b.pop();
	}
	cout << b.front() << "^2";
		return 0;
	*/
	ll start = 2*n*n+n;
	for (int i = 0; i <= n; i++)
	{
		cout << start + i << "^2";
		if (i < n)
			cout << " + ";
	}
	cout << " =" << endl;
	for (int i = n + 1; i <= 2 * n; i++)
	{
		cout << start + i << "^2";
		if (i < 2 * n)
			cout << " + ";
	}
	return 0;
}