#include<stdio.h>
int a[10]={25,65,41,25,68,45,11,
25};

void sort()
{
	for(int j = 1;j < 10;j++)
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

int main()
{
	sort();
	for(int i = 0;i < 10;i++)
	{
		printf("%d ",a[i]);
	}
}