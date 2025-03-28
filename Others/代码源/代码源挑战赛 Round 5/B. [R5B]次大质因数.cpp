#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
bool is_prime(int n)
{
	if (n < 2)
	{
		return false;
	}
	for (int i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	set<int> s;
	int tmp = n;
	for (int i = 2; i <=  tmp / i; ++i)
	{
		if (tmp % i == 0)
		{
			s.insert(i);
			while (tmp % i == 0)
			{
				tmp /= i;
			}
		}
	}
	if(tmp > 1)
	{
		s.insert(tmp);
	}
	if(s.size()<2)cout<<-1<<endl;
	else
	{
		cout<<*prev(prev(s.end()))<<endl;
	}
	return 0;
}