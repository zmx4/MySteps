#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int l, r;
	cin >> l >> r;
	set<int> s;
	for (int i = l; i <= r;i++)
	{
		if(isLeapYear(i))
			s.insert(i);
	}
	cout<<s.size()<<endl;
	for(auto i:s)
		cout<<i<<" ";
	return 0;
}