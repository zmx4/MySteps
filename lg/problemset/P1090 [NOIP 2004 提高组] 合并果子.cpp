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

	int n;
	cin >> n;
	vector<int> a(n);
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < n; ++i) 
	{
		cin >> a[i];
		q.push(a[i]);
	}
	int sum = 0;
	while(q.size() > 1)
	{
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		sum += x + y;
		q.push(x + y);
	}
	cout << sum << endl;







	return 0;
}