#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string s1, s2, s3;
	getline(cin, s1);
	getline(cin, s2);
	getline(cin, s3);
	int pos = s1.find(s2);
	while(pos != string::npos)
	{
		s1.replace(pos, s2.size(), s3);
		pos = s1.find(s2, pos + s3.size());
	}
	cout << s1 << endl;

	return 0;
}