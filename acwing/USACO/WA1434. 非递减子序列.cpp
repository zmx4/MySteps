#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int MOD = 1e9+7;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int k, n;
	cin >> k >> n;
	vector<int> a(k);
	for(int i = 0; i < k; i++)
		cin >> a[i];
	vector<int> res;
	for(int i = 1; i < k; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(a[i]<a[j])
				res.push_back(a[i]*a[j]);
		}
	}
	return 0;
}