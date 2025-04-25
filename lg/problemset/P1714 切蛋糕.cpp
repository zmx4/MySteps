#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e5 + 10;
int q[N], tt = -1, hh = 0;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1), preffix(n + 1);
	int sum = 0, ans = -1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		preffix[i] = preffix[i - 1] + a[i];
	}
	deque<int> q;
	q.push_back(0);
	for (int i = 1; i <= n;i++)
	{
		while(q.front()+k<i)
			q.pop_front();
		ans = max(ans, preffix[i] - preffix[q.front()]);
		while(!q.empty()&&preffix[q.back()]>=preffix[i])
			q.pop_back();
		q.push_back(i);
	}
	cout << ans << endl;
	return 0;
}