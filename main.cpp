#include<iostream>
#include <vector>
using namespace std;
int GCD1(int a,int b)
{
	while(b!=0)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}

int GCD2(int a,int b)
{
	if(b==0)
		return a;
	else
		return GCD2(b,a%b);
}

int lcm(int a, int b)
{
	return a*b / GCD(a, b);
}

void insertsort(int a[], int n)
{
	for (int j = 1; j < n;j++)
	{
		int key = a[j];
		int i = j - 1;
		while(i>=0&&a[i]>key)
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
}

char *StrStr(const char *txt, const char *pat)
{
	if(pat[0]=='\0')return NULL;
	int n = strlen(txt);
	int m = strlen(pat);
	for(int i = 0;i<=n-m;i++)
	{
		int j = 0;
		while(j<m&&txt[i+j]==pat[j])
			j++;
		if(j==m)
			return (char*)txt+i;
	}
	return NULL;
}

bool isPrime(int n)
{
	if(n<)
}