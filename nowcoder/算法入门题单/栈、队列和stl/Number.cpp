#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const ll N = 50000000, M = 7074;
bool state[M+5];
vector<ll> prime, d, c, f;
void judgePrimes()
{
	memset(state, true, sizeof(state));
	state[0] = state[1] = false;
	for (int i = 2; i <= M; i++)
	{
		if (state[i])
		{
			prime.push_back(i);
			for (int j = i * 2; j <= M; j += i)
				state[j] = false;
		}
	}
}
void init()
{
	judgePrimes();
	for(const ll i:prime)
	{
		if(i*i<N)
			d.push_back(i * i);
		if (i * i * i < N)
			c.push_back(i * i * i);
		if (i * i * i * i < N)
			f.push_back(i * i * i * i);
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
	init();
	ll n;
	cin >> n;
	unordered_set<ll> snum;
	for(const ll dn:d)
	{
		for (const ll cn:c)
		{
			for(const ll fn:f)
			{
				ll sum = dn + cn + fn;
				if (sum <= n)
					snum.insert(sum);
			}
		}
	}
	//cout << d.size()<<endl;
	//cout << prime.size()<<endl;
	cout<< snum.size()<<endl;
	return 0;
}