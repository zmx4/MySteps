#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string a;
	cin >> a;
	while(true)
	{
		if(a.empty())
			break;
		if(a[0]=='b')
		{
			cout << "Bad";
			return 0;
		}
		size_t pos = a.find('b');
		if (pos == std::string::npos)
		{
			cout << "Bad";
			return 0;
		}
		a.erase(pos, 1), a.erase(0, 1);
	}
	cout << "Good" << endl;
	return 0;
}