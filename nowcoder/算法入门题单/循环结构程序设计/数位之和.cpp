#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin>>n;
	int sum = 0;
	while(n)
	{
		sum += n % 10;
		n /= 10;
	}
	cout<<sum<<endl;

	return 0;
}