#include<stdio.h>
long Fact(int n)
{
   if(n < 0)return -1;
   else  if(n == 0)return 1;
   else return n*Fact(n-1);
}

int main()
{
   int n;
   scanf("%d",&n);
   printf("%ld",Fact(n));
   return 0;
}