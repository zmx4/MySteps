#include <stdio.h>

void reverse(int n)
{
    if(n <= 9)
	{
		printf("%d",n);
	}
	else
	{
		printf("%d",n%10);
		reverse(n/10);
	}
}
int main()
{
	int a=12345;
	reverse(a);
}