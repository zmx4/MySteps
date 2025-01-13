#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	getline(cin,s);
	int cnt = 0;
	for(auto &c:s)
	{
		if(c>='a'&&c<='z')
			cnt++;
		if(c>='A'&&c<='Z')
			cnt++;
		if(c>='0'&&c<='9')
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}