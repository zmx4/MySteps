#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using namespace std;

ll cal(ll a)
{
	ll sum = 0;
	while(a)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

void solve()
{
	ll a, b;
	cin >> a >> b;
	ll sa = cal(a), sb = cal(b);
	if (a % sb == 0 && !(b % sa == 0))
		cout << "A" << endl;
	else if(b%sa==0&&!(a%sb==0))
		cout << "B" << endl;
	else
	{
		if(a>b)
			cout << "A" << endl;
		else if(a<b)
			cout << "B" << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	int T;cin>>T;
	while(T--)
	{
		solve();
	}
	
	return 0;
}