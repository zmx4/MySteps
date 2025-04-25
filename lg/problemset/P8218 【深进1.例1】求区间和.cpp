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
	vector<int> A(n + 1), preffix(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		preffix[i] = preffix[i - 1] + A[i];
	}
	int m;
	cin >> m;
	while (m--)
	{
		int l, r;
		cin >> l >> r;
		int sum = preffix[r] - preffix[l - 1];
		cout << sum << endl;
	}

	return 0;
}