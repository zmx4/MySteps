#include <bits/stdc++.h>
#define endl "\n"
using ll = long long;
using ull = unsigned long long;
using namespace std;
const int inf = 0x3f3f3f3f;

string eraseprezero(string &s)
{

	int i = 0;
	while (s[i] == '0')
		i++;
	return s.substr(i, s.size() - i);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);


	string s;int n;
	cin >> s >> n;
	//int i;
	if (s.size() <= n)
	{
		cout << "0" << endl;
		return 0;
	}
	while(n)
	{
		int i = 0;
		
		while (i < s.size() - 1 && s[i] <= s[i + 1])
		{
			i++;
		}
		s.erase(i, 1);
		n--;
		//cout << s << endl;
		if(s.size() > 1)
			s = eraseprezero(s);
	}
	cout << s << endl;
	return 0;
}