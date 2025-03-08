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
	int cnt[4] = {0};
	vector<int> a(n+1);
	for(int i=1; i<=n; ++i)
	{
		cin >> a[i];
		cnt[a[i]]++;
	}
	int team = min(cnt[1], min(cnt[2], cnt[3]));
	cout << team << endl;
	vector<int> one, two, three;
	for(int i=1; i<=n; ++i)
	{
		if(a[i] == 1)
			one.push_back(i);
		else if(a[i] == 2)
			two.push_back(i);
		else
			three.push_back(i);
	}
	for(int i=0; i<team; ++i)
		cout << one[i] << " " << two[i] << " " << three[i] << endl;
	return 0;
}