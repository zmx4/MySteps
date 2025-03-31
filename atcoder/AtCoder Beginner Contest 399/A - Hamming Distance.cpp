#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	string str1, str2;
	cin >> str1 >> str2;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			ans++;
	}
	cout << ans << endl;








	return 0;
}