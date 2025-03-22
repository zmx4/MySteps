#include <bits/stdc++.h>
using namespace std;

string removePreZero(string str)
{
	int len = str.length();
	int i = 0;
	while (str[i] == '0')
	{
		i++;
	}
	return str.substr(i);
}

signed main()
{
	string str1,str2;
	cin>>str1>>str2;
	int len1=str1.length(),len2=str2.length();
	string ans1 = "", ans2 = "";
	for(int i=1;i<len1;i++)
	{
		if ((str1[i] - '0') % 2 == (str1[i - 1] - '0') % 2)
		{
			ans1 += max(str1[i], str1[i - 1]);
		}
	}
	for(int i=1;i<len2;i++)
	{
		if ((str2[i] - '0') % 2 == (str2[i - 1] - '0') % 2)
		{
			ans2 += max(str2[i], str2[i - 1]);
		}
	}
	//ans1 = removePreZero(ans1);
	//ans2 = removePreZero(ans2);
	if(ans1==ans2)cout<<ans1<<endl;
	else cout<<ans1<<endl<<ans2<<endl;
	return 0;
}