/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
	string a;cin>>a;
	if(a.length()==4)
	{
		if(a[0]=='0'||a[0]=='1'||(a[0]=='2'&&a[1]<'2'))
		{
			cout<<"20"<<a[0]<<a[1]<<"-"<<a[2]<<a[3];
		}
		if(a[0]>='1')
		{
			cout<<"19"<<a[0]<<a[1]<<"-"<<a[2]<<a[3];
		}
	}
	else
	{
		cout<<a[0]<<a[1]<<a[2]<<a[3]<<"-"<<a[4]<<a[5];
	}
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b, c;
	scanf("%d", &a);
	if (a > 10000)
	{

		b = a / 100;
		c = a % 100;
		printf("%d-%02d", b, c);
	}
	else
	{
		c = a / 100;
		b = a % 100;
		if (c < 22)
			printf("%d-%02d", 2000 + c, b);
		else
			printf("%d-%02d", 1900 + c, b);
	}
	return 0;
}