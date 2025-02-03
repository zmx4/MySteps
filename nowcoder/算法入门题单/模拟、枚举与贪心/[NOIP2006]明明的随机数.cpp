#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	set<int> pq;
	int n;
	cin >> n;
	while(n--)
	{
		int x;
		cin >> x;
		pq.insert(x);
	}
	cout << pq.size() << endl;
	for(auto i:pq)
	{
		cout << i << " ";
	}
	return 0;
}