#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (q.size() < n)
			q.push(x);
		else
			cout << "错误：队列已满。" << endl;
	}
	for (int i = 0; i <= n; i++)
	{
		if (!q.empty())
		{
			cout << q.front() << endl;
			q.pop();
		}
		else
		{
			cout << "错误：队列为空。" << endl;
			cout << -1 << endl;
			cout << "错误：队列为空。" << endl;
		}
	}

	return 0;
}