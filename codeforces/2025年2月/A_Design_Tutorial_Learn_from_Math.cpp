#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isPrime(int n)
{
	if(n==1)
		return false;
	for(int i=2;i*i<=n;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>n;
	vector<int> v;
	for(int i = sqrt(n);i <= n;i++)
	{
		if(!isPrime(i))
		{
			v.push_back(i);
		}
	}
	for(int i = 0;i < v.size();i++)
	{
		for(int j = i;j < v.size();j++)
		{
			if(v[i] + v[j] == n)
			{
				cout<<v[i]<<" "<<v[j]<<endl;
				return 0;
			}
			if(v[i] + v[j] > n)
				break;
		}
	}
	return 0;
}