#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	set<int> s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
	while(!s.empty())
	{
		cout << *s.begin() << " ";
		s.erase(s.begin());
	}
	cout << endl;

	return 0;
}