#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
ll Sum(const string &s)
{
	ll sum = 0;
	for (char c : s)
	{
		sum += (c - '0');
	}
	return sum;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string n;
	ll m,k;
	cin>>n>>m>>k;
	
	ll sum = 0;
	while(k--)
	{
		sum += m;
		sum += Sum(n);
		n = to_string(sum);
		sum = 0;
	}
	cout<<n<<endl;
	return 0;
}