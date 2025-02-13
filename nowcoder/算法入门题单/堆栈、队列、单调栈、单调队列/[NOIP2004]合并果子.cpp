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
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		q.push(x);
	}
	int ans = 0;
	while (q.size() > 1)
	{
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		ans += a + b;
		q.push(a + b);
	}
	cout << ans << endl;

	return 0;
}