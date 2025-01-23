#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		sort(a.begin(), a.end());
		if(a[0]==1)
			cout << -1 << endl;
		else
		{
			cout << "9999999967" << endl;
		}
	}

	return 0;
}