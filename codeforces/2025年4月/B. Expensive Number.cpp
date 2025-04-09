#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

ll swhite(string x)
{
	ll sum = 0;
	for (int i = 0; i < x.size(); i++)
	{
		sum += (x[i] - '0') * pow(10, x.size() - i - 1);
	}
	return sum;
}

void solve()
{
	string n;
	cin >> n;
	if(n.size() == 1)
	{
		cout << 0 << endl;
		return;
	}
	reverse(n.begin(), n.end());
	int cnt = 0;
	bool flag = false;
	for (int i = 0; i < n.size(); i++)
	{
		if(!flag && n[i] == '0')
			cnt++;
		if (n[i] != '0')
			cnt++,flag = true;
	}
	cnt--;
	cout << cnt << endl;
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