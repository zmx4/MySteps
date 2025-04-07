#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1, r = n, al = 0, ar = 0;
	vector<int> work(m + 1, -1);
	int cnt = 0,len = inf;
	for (int i = 1; i <= n;i++)
	{	
		if(work[a[i]] == -1)
		{
			work[a[i]] = i;
			cnt++;
		}
		work[a[i]] = i;
		while(l != i && l < work[a[l]])l++;
		if(cnt == m && i-l+1 < len)
		{
			len = i - l + 1;
			al = l, ar = i;
		}
	}
	cout << al << " " << ar << endl;
	return 0;
}