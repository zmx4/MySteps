#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	string str;
	cin >> str;
	string s2 = str;
	bool hx = 0,hd = 0;
//	for(auto &c:str)c=tolower(c);
//	if(str==s2&&str=="matiji")
//	{
//		cout << "Yes" << endl;
//	}
//	else
//	{
//		cout << "No" << endl;
//	}
	for(auto &c:str)
	{
		if(c >='A'&&c <= 'Z')hd=1;
		else hx = 1;
	}
	if(hd==1&&hx==0)cout << "Yes" << endl;
	else if(hd==0&&hx==1)cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
};
