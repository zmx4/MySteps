#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int N = 100000;
bool state[N];
vector<int> primes;
map<int, bool> st;
void judgePrimes(const int &l, const int &r)
{
	memset(state, true, sizeof(state));
	state[0] = state[1] = false;
	for (int i = 2; i <= r; i++)
	{
		if (state[i])
		{
			if(i>=l&&i<=r)primes.push_back(i);
			for (int j = i * 2; j <= r; j += i)
				state[j] = false;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int l, r;
	cin >> l >> r;
	judgePrimes(l, r);
	//primes.push_back(1000001);
	for (int i = 0; i < primes.size() - 2; i++)
	{
		int a = primes[i], b = primes[i + 1];
		int div = b - a;
		if(st[a]||st[b]||st[b+div])continue;
		auto pos = find(primes.begin(), primes.end(), b + div);
		if (pos != primes.end())
		{
			cout << a << " " << b << " " << b + div;
			st[a] = true;
			st[b] = true;
			st[b + div] = true;
			int temp = b + div + div;
			auto pos = find(primes.begin(), primes.end(), temp);
			while(pos!=primes.end())
			{
				if(!st[i])cout << " " << *pos;
				st[*pos] = true;
				temp+=div;
				pos = find(pos + 1, primes.end(), temp);
			}
			cout << endl;
		}
	}

		return 0;
}