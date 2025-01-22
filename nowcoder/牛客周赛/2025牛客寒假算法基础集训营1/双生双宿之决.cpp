#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		ll a[n];
		memset(a, 0, sizeof(a));
		ll cnt1 = 0, cnt2 = 0;
		int c1=-1, c2=-1;
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			ll x;
			cin >> x;
			if(c1==-1)
			{
				c1 = x;
				cnt1++;
			}
			if(c1!=x && c2==-1)
			{
				c2 = x;
				cnt2++;
			}
			if(c1!=-1 && c1==x)
				cnt1++;
			if(c2!=-1 && c2==x)
				cnt2++;
			if(c1!=x && c2!=x)
			{
				flag = false;
			}
		}
		if(flag)
		{
			if(cnt1==cnt2)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
			cout << "No" << endl;
	}

	return 0;
}