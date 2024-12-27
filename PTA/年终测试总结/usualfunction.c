#include<stdio.h>
#include<string.h>
int gcd1(int  a,int b)
{
	while(b!=0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
}
int gcd2(int  a,int b)
{
	if(b==0)return a;
	else return gcd2(b,a%b);
}
int lcm (int a,int b)
{
	return a*b/gcd1(a,b);
}
void insertsort(int a[],int n)
{
	for(int j = 1;j < n;j++)
	{
		int key = a[j];
		int i = j - 1;
		while(a[i]>key&&i>=0)
		{
			a[i+1]=a[i];
			i--;
		}
		a[i+1]=key;
	}
}
int isPrime(int a)
{
	if(a<=1)return false;
	if(a==2)return true;
	if(a%2==0)return false;
	for(int i = 3;i *i <= a;i++)
	{
		if(a%i==0)
		{
			return false;
		}
	}
	return true;
}
char *StrStr(const char *txt, const char *pat)
{
	if(pat[0]=='\0')return NULL;
	int m = strlen(txt),n = strlen(pat);
	for(int i = 0;i <= m-n;i++)
	{
		if(txt[i]==pat[0])
		{
			int j = 0;
			for(j = 1;j < n;j++)
			{
				if(txt[i]!=pat[0])break;
			}
			if(j==n)return (char *)(txt+i);
		}
	}
	return NULL;
}
