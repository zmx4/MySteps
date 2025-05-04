#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	char c = s[0];
	for(int i = 1; i < n; i++)
	{
		if (s[i] != c)
		{
			cout << "0" << endl;
			return 0;
		}
	}
	cout<<n - 1<<endl;

	return 0;
}