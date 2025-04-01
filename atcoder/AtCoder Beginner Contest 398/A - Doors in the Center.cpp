#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);

	int n;cin>>  n;
	if(n%2==0)
	{
		string s = "";
		for(int i = 0; i < n; i++)
		{
			s += "-";
		}
		s[n/2-1] = '=',s[n/2] = '=';
		cout << s << endl;
	}
	else
	{
		string s = "";
		for(int i = 0; i < n; i++)
		{
			s += "-";
		}
		s[n/2] = '=';
		cout << s << endl;
	}

	return 0;
}