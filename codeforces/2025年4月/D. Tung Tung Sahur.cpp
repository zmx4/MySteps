#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

void solve()
{
	string l1, l2;
	cin >> l1 >> l2;
	int n = l1.size(), m = l2.size();
	if (m < n || m > 2 * n || l1[0] != l2[0])
	{
		cout << "NO" << endl;
		return;
	}
	int lcnt = 0, rcnt = 0;
	//int f = n-1, s = m-1;
	/*
	while(!l1.empty() && !l2.empty())
	{
		int ff = f, ss = s;
		while(ff >= 0 && l1[ff] == l1[f]) ff--;
		while(ss >= 0 && l2[ss] == l2[s]) ss--;
		if ((f - ff) * 2 >= (s - ss) && (f - ff) <= (s - ss) && l1[f] == l2[s])
		{
			l1.erase(l1.begin() + ff + 1);
			f = ff;
			l2.erase(l2.begin() + ss + 1, l2.end());
			s = ss;
		}
		else
		{
			cout << "NO" << endl;
			return;
		}
		if(l1[f]!= l2[s])
		{
			cout << "NO" << endl;
			return;
		}
	}
	*/
	int  l = 1, r = 1, flg = 0;
	l1 = '0'+l1, l2 = '0'+l2;
	while (l <= n && r <= m)
	{
		while(l<=n&&l1[l]=='L')lcnt++,l++;
		while(r<=m&&l2[r]=='L')rcnt++,r++;
		if (!(lcnt <= rcnt && rcnt <= lcnt * 2))
			break;
		lcnt = 0, rcnt = 0;
		while(l<=n&&l1[l]=='R')lcnt++,l++;
		while(r<=m&&l2[r]=='R')rcnt++,r++;
		if (!(lcnt <= rcnt && rcnt <= lcnt * 2))
			break;
		lcnt = 0, rcnt = 0;
		if(l>n&&r>m)flg=1;
	}
	if(flg)cout << "YES" << endl;
	else cout << "NO" << endl;
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