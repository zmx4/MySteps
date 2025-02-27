#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

const int MAXN = 1e9+5;

vector<int> three,five;

void init()
{
	three.push_back(3);
	while(three.back() < MAXN)
	{
		three.push_back(three.back()+3);
	}
	five.push_back(5);
	while(five.back() < MAXN)
	{
		five.push_back(five.back()+5);
	}
}

void solve()
{
	ll n;
	cin >> n;

	ll m3 = (n - 1) / 3;
	ll m5 = (n - 1) / 5;
	ll m15 = (n - 1) / 15;

	ll sum3 = 3 * m3 * (m3 + 1) / 2;
	ll sum5 = 5 * m5 * (m5 + 1) / 2;
	ll sum15 = 15 * m15 * (m15 + 1) / 2;

	cout << sum3 + sum5 - sum15 << endl;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));
	//init();
	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}