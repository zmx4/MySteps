#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i;j++)
		{
			cnt++;
			cout << setw(4) << setfill(' ') <<cnt;
		}
		cout << endl;
	}

	return 0;
}