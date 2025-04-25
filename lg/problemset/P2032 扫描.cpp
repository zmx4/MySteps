#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e4 + 10;
int q[N], head = 0, tail = -1;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
	{
		if (head <= tail && i - k + 1 > q[head])
			head++;
		while (head <= tail && a[q[tail]] <= a[i])
			tail--;
		q[++tail] = i;
		if (i >= k - 1)
			cout << a[q[head]] << endl;
	}
	cout << endl;
	return 0;
}