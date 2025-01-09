#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
const int N = 1e6 + 10;
int stk[N], tt;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	int M;
	cin >> M;
	while(M--)
	{
		string op;
		cin >> op;
		if(op == "push")
		{
			int num;
			cin >> num;
			stk[++tt] = num;
		}
		else if(op == "pop")
		{
			tt--;
		}
		else if(op == "empty")
		{
			if(stk[tt]==0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else if(op == "query")
		{
			cout << stk[tt] << endl;
		}
	}

	return 0;
}