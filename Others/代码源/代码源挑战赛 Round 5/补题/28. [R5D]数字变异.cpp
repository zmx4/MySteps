#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
ll Sum(const string &s)
{
	ll sum = 0;
	for (char c : s)
	{
		sum += (c - '0');
	}
	return sum;
}
ll dsum(ll num)
{
	ll sum = 0;
	while (num)
	{
		sum += num % 10;
		num /= 10;
	}
	return sum;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string n;
	ll m;
	ull k;
	cin >> n >> m >> k;
	ll cur = Sum(n) + m;
	k--;
	if(k==0)
	{
		cout << cur << endl;
		return 0;
	}
	unordered_map<ll, ull> mp;
	mp[cur] = 0;
	ull i = 0;
	while(k>0)
	{
		cur = dsum(cur)+m;
		i++;
		k--;
		if(mp.count(cur))
		{
			ull start = mp[cur];
			ull cycle = i - mp[cur];
			k %= cycle;
			while(k--)
			{
				cur = dsum(cur)+m;
			}
			cout << cur << endl;
			return 0;
		}
		mp[cur] = i;
	}
	cout << cur << endl;
	return 0;
}