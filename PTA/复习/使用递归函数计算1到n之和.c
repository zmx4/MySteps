#include <stdio.h>

int sum( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf ("%d\n", sum(n));

    return 0;
}
int sum( int n )
{
    if(n<=0)return 0;
    int a = 0;
    if(n==1)return 1;
    if(n>1)
    {
        a+=sum(n-1);
    }
    return a;
}