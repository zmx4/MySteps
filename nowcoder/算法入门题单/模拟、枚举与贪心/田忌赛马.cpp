#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	deque<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	ll ans = 0;
	while(!a.empty())
	{
		if(a.front()>b.front())
		{
			ans += 200;
			a.pop_front();
			b.pop_front();
		}
		else if (a.front() < b.front())
		{
			ans -= 200;
			a.pop_back();
			b.pop_front();
		}
		else
		{
			if(a.back() > b.back())
			{
				ans += 200;
				a.pop_back();
				b.pop_back();
			}
			else
			{
				if (a.back() < b.front())
					ans -= 200;
				a.pop_back();
				b.pop_front();
			}
			
		}
	}
	cout << ans << endl;
	return 0;
}