#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	int pos;
	cin >> pos;

	if (pos < 1 || pos > n)
	{
		cout << "错误：不存在这个元素。" << endl;
	}
	else
	{
		a.erase(a.begin() + pos - 1);
	}

	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}