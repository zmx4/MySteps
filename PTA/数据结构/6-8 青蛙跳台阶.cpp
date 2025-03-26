
#include <stdio.h>
int climb(int n);
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", climb(n));
	return 0;
}

/* 请在这里填写答案 */

int climb(int n)
{
	if(n == 0)
		return 0;
	if(n==1)
		return 1;
	if(n==2)
		return 2;
	if(n==3)
		return 4;
	else if(n > 3)return climb(n-1)+climb(n-2)+climb(n-3);
}