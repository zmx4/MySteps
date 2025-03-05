#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int pos;
	cin >> pos;
	if(s1.size()+s2.size() > 1000)
	{
		cout << "错误：插入将导致字符串长度超限。" << endl;
		cout << s1 << endl;
		return 0;
	}
	s1.insert(pos-1, s2);
	cout << s1 << endl;
	return 0;
}