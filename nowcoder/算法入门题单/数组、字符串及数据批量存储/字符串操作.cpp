#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

char s[110];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n, m;
	cin >> n >> m >> s;
	while(m--)
	{
		int a, b;
		char c, d;
		cin >> a >> b >> c >> d;
		a--, b--;
		for(int i = a; i <= b; i++)
		{
			if(s[i] == c)
				s[i] = d;
		}
	}
	cout << s << endl;
	return 0;
}