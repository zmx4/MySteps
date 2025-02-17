#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int maxn = 100150;
map<int, int> nextpos;
bool st[maxn];
int ne[maxn];
priority_queue<int> q;
int a[maxn];
int n, m;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	
	cin >> n >> m;
	
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = n; i >= 1; --i)
	{
		if (nextpos[a[i]] == 0)
		{
			ne[i] = 100050;
		}
		else
		{
			ne[i] = nextpos[a[i]];
		}
		nextpos[a[i]] = i;
	}
	int cnt = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (st[i] == false)
		{
			ans++;
			if (cnt < m)
			{
				cnt++;
				st[ne[i]] = true;
				q.push(ne[i]);
			}
			else
			{
				st[q.top()] = false;
				q.pop();
				st[ne[i]] = true;
				q.push(ne[i]);
			}
			
		}
		else
		{
			st[ne[i]] = true;
			q.push(ne[i]);
		}
	}

	cout << ans << endl;

	return 0;
}