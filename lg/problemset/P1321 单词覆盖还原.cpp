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
	int cnt = 0;
	int b = 0, g = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i]=='b'||s[i+1]=='o'||s[i+2]=='y')
			b++;
		if(s[i]=='g'||s[i+1]=='i'||s[i+2]=='r'||s[i+3]=='l')
			g++;
	}
	cout << b << endl << g << endl;



	return 0;
}