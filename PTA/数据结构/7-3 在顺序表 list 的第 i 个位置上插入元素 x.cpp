#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int pos, x;
	cin >> pos >> x;

	if (n == 10000)
	{
		cout << "错误：表满不能插入。" << "\n";
	}
	else if (pos < 1 || pos > n + 1)
	{
		cout << "错误：插入位置不合法。" << "\n";
	}
	else
	{
		a.insert(a.begin() + pos - 1, x);
	}

	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << " ";

	return 0;
}