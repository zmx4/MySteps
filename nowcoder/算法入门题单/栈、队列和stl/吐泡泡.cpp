#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
char stk[110];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	char readBuffer[1 << 20];
	cin.rdbuf()->pubsetbuf(readBuffer, sizeof(readBuffer));

	string s;

	while (cin >> s)
	{
		int tt = -1;
		for(auto c:s)
		{
			stk[++tt] = c;
			if (stk[tt] == 'o' && tt > 0 && stk[tt - 1] == 'o')
				stk[--tt] = 'O';
			if (stk[tt] == 'O' && tt > 0 && stk[tt - 1] == 'O')
				tt -= 2;
		}
		stk[++tt] = '\0';
		cout << stk << '\n';
	}
	return 0;
}