#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	while(b!=0)
	{
		int t = a % b;
		a = b;
		b = t;
	}
	printf("%d\n", a);
	return 0;
}