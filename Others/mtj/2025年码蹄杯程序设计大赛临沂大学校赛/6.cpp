#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define int long long
using ll = long long;

signed main()
{
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	for(int i = 0;i < min(s1.size(),s2.size());i++)
	{
		if(s1[i]==s2[i])cout<<s1[i];
		else break;
	}
}
