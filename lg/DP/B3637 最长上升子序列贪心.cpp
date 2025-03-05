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
		cin >> a[i];
	vector<int> b;
	for(auto i:a)
	{
		auto it = lower_bound(b.begin(), b.end(), i);
		if(it == b.end())
			b.push_back(i);
		else
			*it = i;
	}
	cout << b.size() << endl;
	return 0;
}