#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	map<int,int> mp;
	vector<int> a(n+1,0);
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	bool flag = false;
	for(int i =1; i <= n-2; i++)
	{
		if(a[i]==a[i+1] && a[i]==a[i+2])
		{
			flag = true;
			break;
		}
	}
	if(flag)
	{
		cout << "Yes" << endl;
		return 0;
	}
	else
	{
		cout << "No" << endl;
		return 0;
	}

	return 0;
}