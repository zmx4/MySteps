#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int a, b;
	cin>>a>>b;
	while(b!=0)
	{
		int temp = a%b;
		a = b;
		b = temp;
	}
	cout<<a<<endl;
	return 0;
}