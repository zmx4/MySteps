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
	sort(a.begin(), a.end());
	if(n%2==0)
	{
		cout<<a[n/2]-1<<endl;
	}
	else
	{
		cout<<a[n/2]-1<<endl;
	}

	return 0;
}