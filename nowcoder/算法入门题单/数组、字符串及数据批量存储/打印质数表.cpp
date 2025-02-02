#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

vector<int> prime(int n)
{
	vector<int> res;
	for(int i = 2; i <= n; i++)
	{
		bool flag = true;
		for(int j = 2; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				flag = false;
				break;
			}
		}
		if(flag)
			res.push_back(i);
	}
	return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin >> n;
	vector<int> res = prime(n);
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << (i == res.size() - 1 ? "\n" : " ");

	return 0;
}