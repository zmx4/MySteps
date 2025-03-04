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
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector<int> ans, temp;
	for (int i = 0; i < n; i++)
	{
		if (temp.empty() || a[i] > temp.back())
		{
			temp.push_back(a[i]);
		}
		else
		{
			if (temp.size() > ans.size())
			{
				ans = temp;
			}
			temp.clear();
			temp.push_back(a[i]);
		}
	}
	if (temp.size() > ans.size())
	{
		ans = temp;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
		if (i < ans.size() - 1)
		{
			cout << " ";
		}
	}

	return 0;
}