#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	string a;
	cin >> a;
	if(a == "0") cout << 1 << endl;
	if(a == "1") cout << 5 << endl;
	else cout << 25 << endl;

	return 0;
}